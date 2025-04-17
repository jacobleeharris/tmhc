This file contains a list of the asset types used by Twisted Metal: Harbor City.

| Location | Extension | Custom Format | Header | Header Size | Header String | Description |
| --- | --- | --- | --- | --- | --- | --- |
/vag | [VPK](#vpk-format) | N | 20 4B 50 56 | 0x800 | "KPV" | Standard PS2 VAG files
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
/skat | [SKX](#skx-format) | Y | 53 4B 45 58 | N/A | "SKEX" |
/rst | [RST](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" | Unrelated to reStructured Text format, has same header as MDR format and file without extension
/rst | [MDR](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" |
/rst | [None](#rstmdr-format) | Y | A5 92 96 4E | N/A | "...N" |
/pts | [GPS](#gpsfpt-format) | Y | 03 20 16 07 | N/A | N/A | Has same header as FPT format
/pts | [PKP](#pkp-format) | Y | 00 20 28 12 | N/A | ". (." | Has same header as CPT, PKS, CPA format
/pts | [CPT](#cpt-format) | Y | 00 20 28 12 |
/pts | [PKS](#pks-format) | Y | 00 20 28 12 |
/pts | [CPA](#cpa-format) | Y | 00 20 28 12 |
/pts | [FPT](#gpsfpt-format) | Y | 03 20 16 07 |
/net | IRX | N | 7F 45 4C 46 | N/A | ".ELF" | Standard PS2 IRX modules
/mov | PSS | N | 00 00 01 BA | N/A | N/A | Standard PS2 movie files
/mod | IRX | N | 7F 45 4C 46 | N/A | ".ELF" | Standard PS2 IRX modules
/mod | SYS | N | 50 53 32 44 | N/A | "PS2D" | Standard PS2 ICON.SYS file
/mod | IMG | N | N/A | N/A | N/A | Standard PS2 IOPRP images
/memcrd | ICO | N | 00 00 01 00 | N/A | N/A | Standard PS2 Memory Card ICO files
/estate | N/A | N/A | N/A | N/A | N/A | Empty folder (unfinished level?)

# VPK format
VPK files are actually VAG files which contain ADPCM audio data. [PSound](https://www.romhacking.net/utilities/679/) / [vgmstream](https://github.com/vgmstream/vgmstream) can be used to play back, extract, and modify data in these files.

# BDD format
BDD files are used for everything from models, chunks, textures, etc.

# BNK format
BNK files are sound bank files which have compressed MIDI / sound fonts packaged inside.

[QuickBMS](https://aluigi.altervista.org/quickbms.htm) with the following script: [twisted_metal_bnk.bms](https://aluigi.altervista.org/bms/twisted_metal_bnk.bms)
can be used to extract files from them. Usually, in the SBL and DAT file format.

[PSound](https://www.romhacking.net/utilities/679/) can also be used to play these files.

# SKX format
SKX files are compressed VAG files. The only example of this is `TM_PS2.SKX` in the `/SND` folder which has 2 VAG files named `KAudioDLL`.
Both appear to be the same and can also be played with [PSound](https://www.romhacking.net/utilities/679/).

# XFX format

# PCM format
This does not appear to be PCM / ADPCM. PSound, vgmstream, nor ffmpeg will play this file. Code insights show this as possibly Nellymoser PCM which ffmpeg should support.

# RST/MDR format
The RST/MDR format describes how levels and objects are rendered in regards to fog, lighting, background and ambient colors, and more. A hex pattern (usable with ImHex) can be found in the `tools` folder of this repository. Files are padded to 0x3FFF (16384 bytes) by default.

# GPS/FPT format

# CPA format

# CPT format

# PKP format
PKP files define where pickups in a level are and what pickups can be found there. PKP files start with the header `00 20 28 12`. Following that is a 12 byte header which tells how many pickup entries are in the file. The entry count is repeated 3 times in the header.

Each entry starts with 12 bytes (3 floats), 32 bytes of padding, a 4 byte pickup type from the list below, and then 16 more bytes of padding which is in total, a 64 byte entry.

Ex:
```
BD B2 C8 C3 // X: -401.396
71 DF B2 43 // Y: 357.746
EC 25 61 42 // Z: 56.287
00 00 00 00 // Padding
00 00 00 00
00 00 00 00
00 00 00 00
00 00 00 00
00 00 00 00
00 00 00 00
00 00 00 00
0C 00 00 00 // Pickup type
00 00 00 00 // Final amount of padding
00 00 00 00
00 00 00 00
01 00 00 00 // Unknown number here
```

Valid pickup types are shown below:
| ID (Hex) | Pickup Name               |
|----------|---------------------------|
| 00       | Machine Gun Pickup        |
| 01       | Fire Missile Pickup       |
| 02       | Homing Missile Pickup     |
| 03       | Skill Missile Pickup      |
| 04       | Gas Can Pickup            |
| 05       | Ricochet Pickup           |
| 06       | Power Missile Pickup      |
| 07       | Turbo Pickup              |
| 08       | Health Pickup             |
| 09       | Environment Attack Pickup |
| 10       | Placeholder               |
| 11       | Axe Pickup                |
| 12       | Bat Pickup                |
| 13       | Placeholder               |
| 14       | Placeholder               |
| 15       | Shotgun Pickup            |
| 16       | Small Trash Can Pickup    |
| 17       | Large Trash Can Pickup    |
| 18       | Chair Pickup              |
| 19       | Wheel Chair Pickup        |
| 0A       | Placeholder               |
| 0B       | Placeholder               |
| 0C       | Placeholder               |
| 0D       | Placeholder               |
| 0E       | Placeholder               |
| 0F       | Placeholder               |

# PPP format

# PTS format
PTS files define where AI cars are allowed to move. Similar to the PKP format, PTS files have a 4 byte header followed by a 12 byte entry count (4-byte entry count repeated thrice), which is followed by a 32 byte entry.

Each entry contains 3 float positions which is then followed by 20 bytes of unknown data at this time.

Ex:
```
E5 4D 18 C6 // X: -9747.47
3A D2 47 45 // Y: 3197.14
24 0C 92 41 // Z: 18.2559
00 00 00 00 // Unknown data follows
00 00 00 03
01 00 10 00
12 00 15 00
00 00 00 00
```
