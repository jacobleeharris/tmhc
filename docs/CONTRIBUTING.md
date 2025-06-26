# Contribution Guide

Welcome!

## Getting started
This project requires several dependencies such as a modern version of [binutils](https://www.gnu.org/software/binutils) for `mips(-el)`, [Ninja](https://ninja-build.org) (for building), and [Python](https://www.python.org) (for setting up the environment).

Optional tools include a modern C/C++ compiler (for type checking) and [objdiff](https://github.com/encounter/objdiff) to aid with diffing incorrect matches.

1. Extract TM.ELF from "TMHC_Later_Working.iso" (2005-08-11)
2. Rename to tmhc.elf
3. Place in config folder
4. Create virtual Python environment using `venv` with command: `python -m venv .venv`
5. Activate virtual Python environment with command: `source .venv/bin/activate`
6. Install dependencies using command: `pip install -U -r requirements.txt`
7. Split the binary using Splat: `./configure.py -c`
8. Run a build with `ninja`

This project uses [pre-commit](https://pre-commit.com) to ensure commits are correctly formatted before pushing changes. Please install and use pre-commit when committing your changes.

## Submitting changes
Changes can be made by submitting a pull request to the main repository from a repository with the changes.

Pull requests are squashed before being merged by maintainers, please do not squash your changes before making a pull request as that erases context for reviews.
