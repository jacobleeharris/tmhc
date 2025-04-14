#include <common.h>

class FileMgr {
private:
    char field0_0x0;
    char field1_0x4;
    char field2_0x8;
    // Short filename
    char field_0xc;
    struct LoadMode {
        char field0_0x0;
        // Has implicit load address?
        char field1_0x4;
        // Load addr
        char field2_0x8;
        // Is file found yet?
        char field_0x14;
    };
    char field_0x44;
    // Tex ID
    char field47_0x38;
    // First Addr
    char field48_0x3c;
    LoadMode loadMode;
    char field51_0x40;
public:
    FileMgr();
    void setLoadMode(int loadMode);
    void initBeforeDbLoad();
    char* addFile(void* buffer, int param_2, char filename, int param_4);
    char getAddrForFile(int param_1);
    int getFileIdxAtAddr(void* buffer);
    char getFirstTexId(int param_1);
    void setFirstTexId(int param_1, int param_2);
    char getFirstAddr(int param_1);
    void setFirstAddr(int param_1, ushort param_2);
    char* getShortFilename(int param_1);
    void setExplicitLoadAddr(void* loadAddr);
    bool needToLoadFile(char* param_1);
    void loadFile(char* param_1, char* param_2, char* param_3, bool param_4, uchar param_5);
    void* loadFile(char* param_1, uchar param_2);
    void* overwriteFile(int param_1, char* param_2, uchar param_3);
    int findFile(char* param_1);
    void getDirName(char* param_1, int param_2);
};

int fileReadCD(char* param_1, void* param_2);
long fileReadHost(char* param_1, void* param_2);

class FileIO {
private:
    const char* DBSERVERNAME = "host0:";
public:
    char read(int __fd, void* __buf, int __nbytes);
    char read(void* __fd, void* __buf, int __nbytes);
    void readChunk(char* param_1, void* param_2, uint param_3);
    int write(int __fd, void* __buf, int __n);
    void formatFilename(char* param_1, char* param_2, char* param_3, char* param_4, bool param_5);
    void pullFilenameFromPath(char* param_1, char* param_2);
    void pullDirNameFromPath(char* param_1, char* param_2);
};
int fileReadChunkCD(char* param_1, void* param_2, uint param_3);
uint fileReadChunkHost(char* param_1, void* param_2, uint param_3);
