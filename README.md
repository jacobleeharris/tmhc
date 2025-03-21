# Twisted Metal: Harbor City
![progress](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/jacobleeharris/tmhc/main/progress/total_progress.json)

This repository contains a work-in-progress matching decompilation of the unreleased PlayStation 2 game "Twisted Metal: Harbor City".

Note: This repository assumes a POSIX environment. Please use WSL or Docker on a Windows machine.

TM.ELF SHA-1 Hash: `59695de214d38d1c0af9167412271fe2a446a13a`

A list of asset types and their descriptions can be found in [ASSETS.md](ASSETS.md).

# Setup
1. Extract TM.ELF from "TMHC_Later_Working.iso" (2005-08-11)
2. Rename to tmhc.elf
3. Place in config folder
4. Create virtual Python environment using `venv` with command: `python -m venv .venv`
5. Activate virtual Python environment with command: `source .venv/bin/activate`
6. Install dependencies using command: `pip install -U -r requirements.txt`
7. Split the binary using Splat: `./configure.py -c`
8. Run a build with `ninja`

# Contributing
Contributions are welcome and are encouraged! If you would like to help out, please create a pull request containing your changes to the repository.

# Tools
This project would not be possible without these tools.
- [GNU GCC](https://github.com/gcc-mirror/gcc) - C/C++ compiler and friends
- [splat](https://github.com/ethteck/splat) - Binary splitter for matching decompilations
- [ninja](https://ninja-build.org) - Quick and simple build system

# References
Code/setup is heavily inspired by:
- [Kingdom Hearts 1 Decompilation](https://github.com/ethteck/kh1)
- [PaRappa the Rapper 2 Decompilation](https://github.com/parappadev/parappa2/)
- [Shadow of the Colossus Decompilation](https://github.com/Fantaskink/SOTC/)
