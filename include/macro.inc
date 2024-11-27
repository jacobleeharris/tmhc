.macro glabel name, visibility=global
.\visibility \name
.type name, @function
\name:
.endm

.macro endlabel label
    .end "\label"
.endm

.macro alabel label
    .global "\label"
    "\label":
.endm

.macro dlabel name, visibility=global
.\visibility \name
.type \name, @object
\name:
.endm

.macro jlabel label
    .global "\label"
    "\label":
.endm
