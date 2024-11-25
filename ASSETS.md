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
/snd | [BNK](#bnk-format) | ? | N/A | N/A | N/A | Possibly Farbrausch V2 Synthesizer Module (.V2M)?
/snd | [XFX](#xfx-format) | ? | 58 46 44 58 | N/A | "XFDX" | Possibly XFX Reverb format?
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

# BDD format

# BNK format
This format appears unrelated to BINK file format. However, Detect-It-Easy detects these files as "Farbrausch V2 Synthesizer Module" (V2M). A V2M player is incapable of playing these files back.

Possibly BINK-encoded audio contained within V2M?

# XFX format

# RST/MDR format

# GPS/FPT format

# CPT/PKS/CPA format