# Twisted Metal: Harbor City
![progress](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/jacobleeharris/tmhc/main/progress/total_progress.json)

This repository contains a work-in-progress matching decompilation of the unreleased PlayStation 2 game "Twisted Metal: Harbor City".

Note: This repository assumes a POSIX environment. Please use WSL or Docker on a Windows machine.

TM.ELF SHA-1 Hash: `59695de214d38d1c0af9167412271fe2a446a13a`

# Documentation
Repository:
- [FAQ](docs/FAQ.md)
- [Contributing](docs/CONTRIBUTING.md)

Game:
- [Classes and header files](docs/CLASSES.md)
- [Assets and file types](docs/ASSETS.md)
- [Packets and networking](docs/PACKETS.md)
- [Named debug pipes](docs/NAMED_DEBUG_PIPES.md)

# Contributing
Contributions are welcome and are encouraged! If you would like to help out, please create a pull request containing your changes to the repository.

See [CONTRIBUTING.md](docs/CONTRIBUTING.md) for more information.

# Tools
This project would not be possible without these tools.
- [GNU GCC](https://github.com/gcc-mirror/gcc) - C/C++ compiler and friends
- [splat](https://github.com/ethteck/splat) - Binary splitter for matching decompilations
- [ninja](https://ninja-build.org) - Quick and simple build system

# References
Code/setup is heavily inspired by:
- [Kingdom Hearts 1 Decompilation](https://github.com/ethteck/kh1)
- [PaRappa the Rapper 2 Decompilation](https://github.com/parappadev/parappa2)
- [Shadow of the Colossus Decompilation](https://github.com/Fantaskink/SOTC)
