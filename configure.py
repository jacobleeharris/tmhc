#! /usr/bin/env python3

# SPDX-License-Identifier: MIT

import argparse
import os
import shutil
import subprocess
import sys
import re

from   pathlib     import Path
from   typing      import Dict, List, Set, Union

import ninja_syntax

import splat
import splat.scripts.split as split
from   splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent
TOOLS_DIR = ROOT / "tools"

YAML_FILE = "config/tmhc.yaml"
BASENAME = "tmhc"
LD_PATH = f"config/{BASENAME}.ld"
ELF_PATH = f"build/{BASENAME}"
MAP_PATH = f"config/{BASENAME}.map"
PRE_ELF_PATH = f"build/{BASENAME}.elf"

COMMON_INCLUDES = "-Iinclude -Iinclude/tmhc -Iinclude/sdk -Iinclude/sdk/ee -Iinclude/gcc -Iinclude/gcc/gcc-lib -Iinclude/gcc/machine -Iinclude/gcc/sys"
COMPILER_DIR = f"{TOOLS_DIR}/ee-gcc2.95.3-136/bin"

COMPILER_FLAGS     = "-nostdinc -Wall -fno-exceptions -ffreestanding -O2 -G8"
COMPILER_FLAGS_CPP = "-nostdinc -Wall -fno-exceptions -ffreestanding -x c++ -O2 -G8"

COMPILE_CMD = (
    f"wine {COMPILER_DIR}/ee-gcc.exe -c {COMMON_INCLUDES} {COMPILER_FLAGS}"
)
COMPILE_CMD_CPP = (
    f"wine {COMPILER_DIR}/ee-gcc.exe -c {COMMON_INCLUDES} {COMPILER_FLAGS_CPP}"
)

def exec_shell(command: List[str], stdout = subprocess.PIPE) -> str:
    ret = subprocess.run(
        command, stdout=stdout, stderr=subprocess.PIPE, text=True
    )
    return ret.stdout


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    if os.path.exists(".ninja_log"):
        os.remove(".ninja_log")
    if os.path.exists("build.ninja"):
        os.remove("build.ninja")
    if os.path.exists("{BASENAME}.ld"):
        os.remove("{BASENAME}.ld")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def build_stuff(linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    # Rules
    cross = "mipsel-linux-gnu-"
    ld_args = f"-T config/undefined_syms.txt -T config/undefined_syms_auto.txt -T config/undefined_funcs_auto.txt -Map $mapfile -T $in -o $out"

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {COMMON_INCLUDES} $in -o - | {cross}as -no-pad-sections -march=5900 -mabi=eabi -Iinclude -o $out && python3 tools/elf_patcher.py $out gas $override",
    )

    ninja.rule(
        "cpp",
        description="cpp $in",
        command=f"{COMPILE_CMD_CPP} $in -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{COMPILE_CMD} $in -o $out && {cross}strip $out -N dummy-symbol-name",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross}ld {ld_args}",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if entry.object_path.is_relative_to(Path("build/asm/sdk")):
            override = "--section-align .text:0x4"
        elif entry.object_path.is_relative_to(Path("build/asm/data/section")):
            override = "--section-align .data:0x1"
        elif entry.object_path.is_relative_to(Path("build/asm/data")):
            override = "--section-align .data:0x4"
        else:
            override = ""

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            build(entry.object_path, entry.src_paths, "as", variables={"override": override})
        elif isinstance(seg, splat.segtypes.common.cpp.CommonSegCpp):
            build(entry.object_path, entry.src_paths, "cpp")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            build(entry.object_path, entry.src_paths, "cc")
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin) or isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin) or isinstance(seg, splat.segtypes.common.rodatabin.CommonSegRodatabin):
            build(entry.object_path, entry.src_paths, "as", variables={"override": override})
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    ninja.build(
        ELF_PATH + ".ok",
        "sha1sum",
        "checksum.sha1",
        implicit=[ELF_PATH],
    )

# Pattern to workaround unintended nops around loops
COMMENT_PART = r"\/\* (.+) ([0-9A-Z]{2})([0-9A-Z]{2})([0-9A-Z]{2})([0-9A-Z]{2}) \*\/"
INSTRUCTION_PART = r"(\b(bne|bnel|beq|beql|bnez|bnezl|beqzl|bgez|bgezl|bgtz|bgtzl|blez|blezl|bltz|bltzl|b)\b.*)"
OPCODE_PATTERN = re.compile(f"{COMMENT_PART}  {INSTRUCTION_PART}")

PROBLEMATIC_FUNCS = set(
    [
        # tmhc/Slink
        "init__5Slinki",
        "deinit__5Slink",
        "update__5Slink",
        "writeFile__5SlinkPciiT1PFiiPv_vPv",
        "readFile__5SlinkPciiT1PFiiPv_vPv",
        "enableCommunicationFlow__5Slinkb",
        "updateItem__5SlinkPUc",
        "runFromDest__5Slink",
        "getFileHandle__5Slink",
        "responseFileExists__5SlinkUc",
        "sendCommand__5SlinkUcUcUi",
        "debugPrint__5SlinkPc",
        "__8SlinkQuei",
        "_$_8SlinkQue",
        "SpaceAvailable__8SlinkQue",
        "IsEmpty__8SlinkQue",
        "Take__8SlinkQue",
        "SpaceUsed__8SlinkQue",
        "Platform_WriteFlush__5Slink",
        "Platform_Read__5SlinkPUci",
        "Platform_Reset__5Slink",
        "Platform_Deinit__5Slink"
    ]
)


def replace_instructions_with_opcodes(asm_folder: Path) -> None:
    nm_folder = ROOT / asm_folder / "nonmatchings"

    for p in nm_folder.rglob("*.s"):
        if p.stem not in PROBLEMATIC_FUNCS:
            continue

        with p.open("r") as file:
            content = file.read()

        if re.search(OPCODE_PATTERN, content):
            # Reference found
            # Embed the opcode, we have to swap byte order for correct endianness
            content = re.sub(
                OPCODE_PATTERN,
                r"/* \1 \2\3\4\5 */  .word      0x\5\4\3\2 /* \6 */",
                content,
            )

            # Write the updated content back to the file
            with p.open("w") as file:
                file.write(content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    parser.add_argument(
        "-csrc",
        "--cleansrc",
        help="Clean the 'src' folder",
        action="store_true",
    )
    parser.add_argument(
        "-noloop",
        "--no-short-loop-workaround",
        help="Do not replace branch instructions with raw opcodes for functions that trigger the short loop bug",
        action="store_true",
    )
    args = parser.parse_args()

    if args.clean:
        clean()

    if args.cleansrc:
        shutil.rmtree("src", ignore_errors=True)

    split.main([Path(YAML_FILE)], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)

    if not args.no_short_loop_workaround:
        replace_instructions_with_opcodes(split.config["options"]["asm_path"])

    if not os.path.isfile("compile_commands.json"):
        exec_shell(["ninja", "-t", "compdb"], open("compile_commands.json", "w"))
