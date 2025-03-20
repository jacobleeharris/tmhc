#include <tmhc/McFileInfo.h>

McFileInfo::McFileInfo() {
    this->field_0x300 = 0;
    this->field772_0x304 = NULL;
    this->field773_0x308 = NULL;
    this->field774_0x30c = NULL;
    this->field775_0x310 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", __as__10McFileInfoR10McFileInfo);
INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", setDirectory__10McFileInfoPc);
INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", addFile__10McFileInfoPcPvUib);

void McFileInfo::setScreenName(char* screenName) {
    this->field774_0x30c = screenName;
}

void McFileInfo::setIconName(char* iconName) {
    this->field773_0x308 = iconName;
}

void McFileInfo::setFileTitle(char* titleName) {
    this->field775_0x310 = titleName;
}
