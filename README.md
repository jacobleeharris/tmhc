# Twisted Metal: Harbor City
This repository contains a work-in-progress matching decompilation of the unreleased PlayStation 2 game "Twisted Metal: Harbor City".

Note: This repository assumes a POSIX environment. Please use WSL or Docker on a Windows machine.

# Setup
1. Extract SLPS_123.45 from "Twisted_Metal-Harbor_City-2004-01-29-Early_02-Rebuild.iso"
2. Place in config folder
3. Create virtual Python environment using `venv` with command: `python -m venv .venv`
4. Activate virtual Python environment with command: `source .venv/bin/activate`
5. Install dependencies using command: `pip install -U -r requirements.txt`

# Contributing
Contributions are welcome and are encouraged! If you would like to help out, please create a pull request containing your changes to the repository.

# Tools
This project would not be possible without these tools.
- [GNU GCC](https://github.com/gcc-mirror/gcc) - C/C++ compiler and friends
- [splat](https://github.com/ethteck/splat) - Binary splitter for matching decompilations
