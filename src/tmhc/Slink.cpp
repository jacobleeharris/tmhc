#include <Slink.h>
#include <string.h>
#include <stdio.h>

extern void *m_pFileBufferLoc;
extern SlinkQue m_ReadQ;
extern SlinkQue m_WriteQ;

// INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", __5Slink);
Slink::Slink()
{
    this->field_0x30 = 0;
    this->field_0x31 = 0;
    this->field_0x32 = FALSE;
}

Slink::~Slink()
{
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", init__5Slinki);

void Slink::deinit()
{
    long value = sendCommand('\t', '\0', 0);
    if (value == 7)
    {
        Platform_WriteFlush();
    }
    Platform_Deinit();
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", update__5Slink);

uchar Slink::isInitted()
{
    return this->field_0x32;
}

bool Slink::fileExists(char *file, void (*callback)(int, int, void *), void *param_3)
{
    if (callback != NULL)
    {
        (*callback)(1, 0, param_3);
    }
    return 1;
}

bool Slink::writeFile(char *param_1, int param_2, int param_3, char *param_4, void (*callback)(int, int, void *), void *param_6)
{
    if (callback != NULL)
    {
        (*callback)(1, 0, param_6);
    }
    return 1;
}

bool Slink::readFile(char *param_1, int param_2, int param_3, char *param_4, void (*callback)(int, int, void *), void *param_6)
{
    if (callback != NULL)
    {
        (*callback)(1, 0, param_6);
    }
    return 1;
}

void Slink::setReceiveFileCallback(void (*param_1)(int, int, void *), void *param_2, char *param_3)
{
    this->field0_0x0 = param_1;
    this->field1_0x4 = param_2;
    this->field2_0x8 = param_3;
}

void Slink::enableCommunicationFlow(bool param_1)
{
    Platform_ManualFlowControl(param_1);
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendName__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendVersion__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileAck__5SlinkUcUc);
/* void Slink::sendVersion() {
    uchar buffer[16];
    uchar* version = this->getVersionString();
    int length = strlen((char*) version) + 1;
    sendCommand(0x82, '\0', length);
    buffer[0] = 0;
    uint i = 0;
    if (length != 0) {
        for (i = 0; i < length; i++) {
            uchar currentChar = version[i];
            buffer[0] = currentChar ^ buffer[0];
        }
    }
    Platform_Write(version, length);
    Platform_Write(buffer, 1);
    Platform_WriteFlush();
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", updateItem__5SlinkPUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileBlock__5SlinkUc);

/*long Slink::sendFileAck(uchar i, uchar param_2)
{
    if (param_2 == 0x85)
    {
        FileAck *ack = &acks[i];
        if (++ack->field_1 <= ack->field_2)
        {
            return sendFileBlock(i);
        }
    }
    else
    {
        return printf("Retry block %d\n", acks[i].field_1);
    }
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", receiveFile__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", runFromDest__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", getFileHandle__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", responseFileExists__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendCommand__5SlinkUcUcUi);

int Slink::debugPrint(char *param_1)
{
    return printf(param_1);
}

SlinkQue::SlinkQue(int size)
{
    this->buffer = new uchar[size];
    this->size = size;
    this->field2_0x8 = 0;
    this->currentPos = 0;
}

SlinkQue::~SlinkQue()
{
    if (this->buffer != NULL)
    {
        delete[] this->buffer;
    }
}

int SlinkQue::SpaceAvailable()
{
    int currentPos = this->currentPos;
    int iVar2 = this->field2_0x8;
    if (iVar2 > currentPos)
    {
        return iVar2 - currentPos;
    }
    return (this->size - currentPos) + iVar2;
}

void SlinkQue::Put(uchar param_1)
{
    int currentPos = this->currentPos;
    this->buffer[currentPos] = param_1;
    currentPos++;
    this->currentPos = currentPos;
    if (this->size <= currentPos)
    {
        this->currentPos = 0;
    }
}

bool SlinkQue::IsEmpty()
{
    return this->currentPos == this->field2_0x8;
}

uchar SlinkQue::Take()
{
    uchar value = this->buffer[this->field2_0x8++];
    if (this->size <= this->field2_0x8)
    {
        this->field2_0x8 = 0;
    }
    return value;
}

int SlinkQue::SpaceUsed()
{
    return this->size - SpaceAvailable();
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Disconnect__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Write__5SlinkPUci);
/*int Slink::Platform_Write(uchar* buf, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (SlinkQue::SpaceAvailable == 0)
        {
            Platform_WriteFlush();
        }

        SlinkQue::Put(m_WriteQ, buf[i]);
    }

    return length;
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_WriteFlush__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Read__5SlinkPUci);

void Slink::Platform_RunFromDest(int param_1)
{
}

void *Slink::Platform_GetDefaultLoadAddr()
{
    if (m_pFileBufferLoc == NULL)
    {
        m_pFileBufferLoc = new void *[0x19000 / sizeof(void *)];
    }
    return m_pFileBufferLoc;
}

void Slink::Platform_ManualFlowControl(bool param_1)
{
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Init__5Slinki);
/*int Slink::Platform_Init(int size)
{
    Platform_Disconnect();

    int pipeType = 3;
    int handle = sceOpen("host0:\\\\.\\pipe\\slinkPipe", pipeType);
    m_pipefd = handle;

    if (handle < 0) {
        handle = 0;
        m_pipefd = _heap_size;
    } else {
        printf("Pipe handle: %d\n", handle);
        if (size == 0) {
            size = 0x1000;
        }
        m_ReadQ = SlinkQue(size);
        m_WriteQ = SlinkQue(size);
    }
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Reset__5Slink);

void Slink::Platform_Deinit()
{
    Platform_Disconnect();
}
