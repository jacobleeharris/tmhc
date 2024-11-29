#include <tmhc/McFileInfo.h>

INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", __10McFileInfo);
INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", __as__10McFileInfoR10McFileInfo);
INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", setDirectory__10McFileInfoPc);
INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", addFile__10McFileInfoPcPvUib);
// INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", setScreenName__10McFileInfoPc);
// INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", setIconName__10McFileInfoPc);
// INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", setFileTitle__10McFileInfoPc);

/*bool McFileInfo::operator==(const McFileInfo &other) const {
    return this->field_0x300 == other.field_0x300 &&
        this->field772_0x304 == other.field772_0x304 &&
        this->field773_0x308 == other.field773_0x308 &&
        this->field774_0x30c == other.field774_0x30c &&
        this->field775_0x310 == other.field775_0x310;
}*/

void McFileInfo::setScreenName(char* screenName) {
    this->field774_0x30c = screenName;
}

void McFileInfo::setIconName(char* iconName) {
    this->field773_0x308 = iconName;
}

void McFileInfo::setFileTitle(char* titleName) {
    this->field775_0x310 = titleName;
}