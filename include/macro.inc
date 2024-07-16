.macro glabel label
    .global "\label"
    .type "\label", @function
    .ent "\label"
    "\label":
.endm

.macro endlabel label
    .end "\label"
.endm

.macro alabel label
    .global "\label"
    "\label":
.endm

.macro dlabel label
    .global "\label"
    "\label":
.endm

.macro jlabel label
    .global "\label"
    "\label":
.endm
