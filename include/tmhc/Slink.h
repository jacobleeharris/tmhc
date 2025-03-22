#include <common.h>

// OpenSSL
struct EVP_PKEY_CTX;

class Slink {
private:
    void(*field0_0x0)(int, int, void*);
    void* field1_0x4;
    char* field2_0x8;

    // TODO: members here

    char field_0x30;
    char field_0x31;
    bool field_0x32;
    // undefined
    void* field_0x33;
    int field_0x34;
public:
    Slink();
    ~Slink();
    int init(EVP_PKEY_CTX *ctx);
    void deinit();
    void update();
    bool isInitted();
    bool fileExists(char* file, void(*callback)(int, int, void*), void* param_3);
    bool writeFile(char* param_1, int param_2, int param_3, char* param_4, void(*callback)(int, int, void*), void* param_6);
    bool readFile(char *param_1, int param_2, int param_3, char *param_4, void(*callback)(int, int, void*), void *param_6);
    void setReceiveFileCallback(void(*param_1)(int, int, void*), void* param_2, char* param_3);
    void enableCommunicationFlow(bool param_1);
    void sendName(uchar param_1);
    void sendVersion();
    void updateItem(uchar param_1);
    void sendFileBlock(uchar param_1);
    void sendFileAck(uchar param_1, uchar param_2);
    void receiveFile(uchar param_1);
    void runFromDest();
    uint getFileHandle();
    // Return type of bool?
    void responseFileExists(uchar param_1);
    long sendCommand(uchar param_1, uchar param_2, uint param_3);
    int debugPrint(char* param_1);

    void Platform_Disconnect();
    int Platform_Write(uchar* param_1, int param_2);
    int Platform_WriteFlush();
    int Platform_Read(uchar* param_1, int param_2);
    void Platform_RunFromDest(int param_1);
    void* Platform_GetDefaultLoadAddr();
    void Platform_ManualFlowControl(bool param_1);

    // Determine return type
    void Platform_Init(int param_1);
    void Platform_Reset();
    void Platform_Deinit();
};

class SlinkQue {
    private:
        // Determine type of queue
        uchar* buffer;
        int size;
        int field2_0x8;
        int field3_0xc;
    public:
        SlinkQue(int size);
        ~SlinkQue();
        int SpaceAvailable();
        void Put(uchar param_1);
        bool IsEmpty();
        // Determine return type
        uchar Take();
        int SpaceUsed();
};
