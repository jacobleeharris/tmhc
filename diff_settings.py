def apply(config, args):
    config["arch"] = "mipsee"
    config["baseimg"] = f"config/tmhc.elf"
    config["myimg"] = f"build/tmhc.elf"
    config["mapfile"] = f"config/tmhc.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include",
        "assets"
    ]
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-Mreg-names=n64"]
    config["expected_dir"] = f"expected/"