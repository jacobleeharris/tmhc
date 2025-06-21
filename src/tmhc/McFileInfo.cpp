#include <tmhc/McFileInfo.h>

McFileInfo::McFileInfo() {
    this->field_0x300 = 0;
    this->field772_0x304 = NULL;
    this->field773_0x308 = NULL;
    this->field774_0x30c = NULL;
    this->field775_0x310 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/tmhc/McFileInfo", __as__10McFileInfoR10McFileInfo);
/*McFileInfo& McFileInfo::operator=(const McFileInfo& other) {
    McFileInfo info;
    info.field_0x300 = other.field_0x300;
    info.field772_0x304 = other.field772_0x304;
    info.field773_0x308 = other.field773_0x308;
    info.field774_0x30c = other.field774_0x30c;
    info.field775_0x310 = other.field775_0x310;

    if (other.field_0x300 << 0x18) {

    }

    return info;
}*/

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
