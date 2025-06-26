#!/usr/bin/env python3

# Thanks to AngheloAlf for this Splat extension.

from __future__ import annotations

from pathlib import Path
from typing import List, Optional

from splat.segtypes.common.data import CommonSegData
from splat.segtypes.linker_entry import LinkerEntry, LinkerWriter
from splat.util import log

class LinkerEntryLinkonce(LinkerEntry):
    def __init__(
        self,
        segment: PS2SegLinkonce,
        src_paths: List[Path],
        object_path: Path,
        section_order: str,
        section_link: str,
        symbol_name: str,
        noload: bool = False,
    ):
        super().__init__(segment, src_paths, object_path, section_order, section_link, noload)
        self.full_section = f".gnu.linkonce.d.{symbol_name}"

    def emit_entry(self, linker_writer: LinkerWriter):
        assert self.object_path is not None
        linker_writer._write_object_path_section(self.object_path, self.full_section)


class PS2SegLinkonce(CommonSegData):
    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )
        symbol = None
        if isinstance(yaml, dict):
            symbol = yaml.get("symbol")
        elif len(args) > 0:
            symbol = args[0]

        if symbol is None or not isinstance(symbol, str):
            if rom_start is not None:
                log.error(f"Missing 'symbol' argument for '.linkonce' section '{name}' (0x{rom_start:08X})")
        self.symbol_name: Optional[str] = symbol

    def get_section_flags(self):
        return "a"

    def get_linker_section(self) -> str:
        return ".linkonce"

    def get_linker_entries(self) -> List[LinkerEntry]:
        path = self.out_path()
        symbol_name = self.symbol_name
        entries = []

        if path and symbol_name:
            entries.append(LinkerEntryLinkonce(
                self,
                [path],
                path,
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                symbol_name,
                self.is_noload(),
            ))

        return entries
