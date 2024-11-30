def apply(config, args):
    config["arch"] = "mipsee"
    config["baseimg"] = f"config/TMHC.ELF"
    config["myimg"] = f"build/tmhc-rom.elf"
    config["mapfile"] = f"config/tmhc.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include"
    ]
    config["make_command"] = ["make"]
    config["objdump_flags"] = ["-Mreg-names=n64"]
    config["expected_dir"] = f"expected/"