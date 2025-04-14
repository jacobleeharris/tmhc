#include <common.h>

class Switch;

class McTaskQueue {
private:
    // Index
    int field_0x50;
    // Widget to be switched to
    Switch* field84_0x54;
public:
    void setIdx(int newIdx);
    int getIdx();
    void setWidgetSwitch(Switch* widgetSwitch);
};

class McTask {
private:
public:
    virtual void onFinished(McTaskQueue* taskQueue);
    virtual void reset();
};

class McOpenBasicFiles : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McCloseBasicFiles : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McWriteBasicFileData : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McLoadFile : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McSaveFile : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McListRootDirectory : McTask {
private:
    // Default index
    int field_0x31;

    // Num directories
    int field3252_0xcb4;
public:
    void setDefaultIdx(int defaultIdx);
    int getNumDirectories();
    char* getDirName(int idx);
};

class McCheckForPartialDirectory : McTask {
private:
    // Found valid directory?
    bool field_0xc96;
    // Directory name
    char* field_0xc8c;
    // Partial directory index
    char field_0xc94;
    // Complete directory index
    char field_0xc95;
public:
    bool foundvaliddirectory();
    void setDirectoryName(char* name);
    void setPartialDirIdx(int idx);
    void setCompleteDirIdx(int idx);
};

class McDoesFileExist : McTask {
private:
    char* field_0x8;
    // Found file index
    char field_0xc;
    // File found index
    char field_0xd;
    // File not found index
    char field14_0xe;
public:
    void setFileFoundIdx(char idx);
    void setFileNotFoundidx(char idx);
    char getFoundFile();
    void setFileName(char* name);
};

class McUpdateState : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McFormat : McTask {
private:
public:
    void onFinished(McTaskQueue* taskQueue);
};

class McScrambleIcon : McTask {
private:
    // Directory name
    char* field2_0x8;
    // Uses fix icon
    bool field_0xc;
public:
    McScrambleIcon();
    void setDirectoryName(char* name);
    void setFixIcon(bool usesFixIcon);
    void onFinished(McTaskQueue* taskQueue);
};

class McSetupGameDir : McTask {
private:
    // Directory name
    char* field3206_0xc8c;

    // Used in clear()
    long field3207_0xc90;
    long field0_0x0;
public:
    McSetupGameDir();
    void setDirectoryname(char* name);
    void onFinished(McTaskQueue* taskQueue);
    void clear();
};
