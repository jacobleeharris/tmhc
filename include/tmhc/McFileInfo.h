#include <common.h>

class McFileInfo {
public:
    McFileInfo();
    bool operator==(const McFileInfo& other) const;
    void setDirectory(char* directory);
    void addFile(char* file, void* param_2, u32 param_3, bool param_4);
    void setScreenName(char* screenName);
    void setIconName(char* iconName);
    void setFileTitle(char* titleName);
private:
    u8 padding[0x300];

    s8 field_0x300;

    // Directory
    char* field772_0x304;
    // Icon name
    char* field773_0x308;
    // Screen name
    char* field774_0x30c;
    // File title
    char* field775_0x310;
};
