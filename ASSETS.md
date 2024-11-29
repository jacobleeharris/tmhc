This file contains a list of the asset types used by Twisted Metal: Harbor City.

| Location | Extension | Custom Format | Header | Header Size | Header String | Description |
| --- | --- | --- | --- | --- | --- | --- |
/vag | [VPK](#vpk-format) | Y | 20 4B 50 56 | 0x800 | "KPV" | Unrelated to Valve's Package format.
/trans | [BDD](#bdd-format) | Y | unique | N/A | N/A | Header starts with name of level.
/suburbs | BDD
/stadium | BDD
/shipyard | BDD
/shell | BDD
/scenter | BDD
/railyard | BDD
/mini_dt | BDD
/lvl | BDD
/impound | BDD
/harbor2 | BDD
/harbor1 | BDD
/gothfoot | BDD
/goth | BDD
/globals | BDD
/ghetto | BDD
/freeway | BDD
/downtown | BDD
/docks | BDD
/chars | BDD
/cars | BDD
/asylumt | BDD
/asylumb | BDD
/airport | BDD
/aicars | BDD
/snd | [BNK](#bnk-format) | ? | N/A | N/A | N/A | Twisted Metal sound bank files
/snd | [XFX](#xfx-format) | ? | 58 46 44 58 | N/A | "XFDX" | Possibly XFX Reverb format?
/snd | [PCM](#pcm-format) | ? | unique | | N/A | Unrelated to regular PCM
/skat | CTL | Y | 53 43 54 4C | N/A | "SCTL" |
/skat | SKX | Y | 53 4B 45 58 | N/A | "SKEX" |
/rst | [RST](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" | Unrelated to reStructured Text format, has same header as MDR format and file without extension
/rst | [MDR](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" |
/rst | [None](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" |
/pts | [GPS](#gpsfpt-format) | Y | 03 20 16 07 | N/A | N/A | Has same header as FPT format
/pts | [PKP](#cptpkscpa-format) | Y | 00 20 28 12 | N/A | ". (." | Has same header as CPT, PKS, CPA format
/pts | [CPT](#cptpkscpa-format) | Y | 00 20 28 12 |
/pts | [PKS](#cptpkscpa-format) | Y | 00 20 28 12 |
/pts | [CPA](#cptpkscpa-format) | Y | 00 20 28 12 |
/pts | [FPT](#gpsfpt-format) | Y | 03 20 16 07 |
/net | IRX | N | 7F 45 4C 46 | N/A | ".ELF" | Standard PS2 IRX modules
/mov | PSS | N | 00 00 01 BA | N/A | N/A | Standard PS2 movie files
/mod | IRX | N | 7F 45 4C 46 | N/A | ".ELF" | Standard PS2 IRX modules
/mod | SYS | N | 50 53 32 44 | N/A | "PS2D" | Standard PS2 ICON.SYS file
/mod | IMG | N | N/A | N/A | N/A | Standard PS2 IOPRP images
/memcrd | ICO | N | 00 00 01 00 | N/A | N/A | Standard PS2 Memory Card ICO files
/estate | N/A | N/A | N/A | N/A | N/A | Empty folder (unfinished level?)

# VPK format
VPK files are actually VAG files which contain ADPCM audio data. PSound / [vgmstream](https://github.com/vgmstream/vgmstream) can be used to play back, extract, and modify data in these files.

# BDD format
BDD files are used for everything from models, chunks,

# BNK format
BNK files are sound bank files which have compressed MIDI / sound fonts packaged inside.

[QuickBMS](https://aluigi.altervista.org/quickbms.htm) with the following script: [twisted_metal_bnk.bms](https://aluigi.altervista.org/bms/twisted_metal_bnk.bms)
can be used to extract files from them. Usually, in the SBL and DAT file format.

# XFX format

# PCM format
This does not appear to be PCM / ADPCM. PSound, vgmstream, nor ffmpeg will play this file. Code insights show this as possibly Nellymoser PCM which ffmpeg should support.

# RST/MDR format
Padded to 0x3FFF (16384 bytes)

# GPS/FPT format

# CPT/PKS/CPA format
