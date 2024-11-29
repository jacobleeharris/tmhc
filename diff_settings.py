def apply(config, args):
    config["baseimg"] = f"config/TMHC.elf"
    config["myimg"] = f"build/tmhc.elf"
    config["mapfile"] = f"config/tmhc.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include"
    ]
    # config["show_line_numbers_default"] = True
    # config["arch"] = "mips"
    # config["map_format"] = "gnu" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    config["expected_dir"] = "expected/" # needed for -o
    # config["makeflags"] = []
    # config["objdump_executable"] = ""
