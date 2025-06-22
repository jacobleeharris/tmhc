# Named debug pipes

## slinkPipe
The slinkPipe (located at `host0:\\\\.\\pipe\\slinkPipe`) is used to interact with the sound link from a developer's machine.
The pipe interacts over a serial-like interface over a full duplex pipe. Due to the nature of the interface, the pipe may only be used on Windows
since Unix-based OSes do not implement full duplex pipes.

Full duplex pipes are pipes which can be read and written to at the same time. Enabling the slinkPipe in-game without an interacting pipe server will cause
the game to freeze. If no data is written to the slinkPipe after a command is written (from the game) will also cause the game to freeze waiting for input from the
host machine.

Using this pipe on an emulator (such as PCSX2) requires enabling an option in the emulating settings called "Enable host filesystem" since pipes are similar to files.

Bytes are written one byte at a time (via `Slink::Platform_Write`) through a stack (`SlinkQue`).

No interacting server has been written at this time.

Decompilation of this class can be found in [Slink.cpp](../src/tmhc/Slink.cpp).

## xfaderPipe

No research done at this time (`host0:\\\\.\\pipe\\xfaderPipe`).
