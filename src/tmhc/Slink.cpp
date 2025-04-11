#include <Slink.h>
#include <string.h>
#include <stdio.h>

extern void* m_pFileBufferLoc;
extern SlinkQue* m_ReadQ;
extern SlinkQue* m_WriteQ;

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", __5Slink);
/*Slink::Slink() {
    this->field_0x30 = 0;
    this->field_0x31 = 0;
    this->field_0x32 = FALSE;
    this->field_0x34 = (int)&D_023C7C50;
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", _$_5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", init__5Slinki);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", deinit__5Slink);
/*void Slink::deinit() {
    long value = sendCommand('\t', '\0', 0);
    if (value == 7) {
        Platform_WriteFlush();
    }
    Platform_Deinit();
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", update__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", isInitted__5Slink);
/*bool Slink::isInitted() {
    return this->field_0x32;
}*/

bool Slink::fileExists(char* file, void(*callback)(int, int, void*), void* param_3) {
    if (callback != NULL) {
        (*callback)(1, 0, param_3);
    }
    return 1;
}

bool Slink::writeFile(char* param_1, int param_2, int param_3, char* param_4, void(*callback)(int, int, void*), void* param_6) {
    if (callback != NULL) {
        (*callback)(1, 0, param_6);
    }
    return 1;
}

bool Slink::readFile(char *param_1, int param_2, int param_3, char *param_4, void(*callback)(int, int, void*), void *param_6) {
    if (callback != NULL) {
        (*callback)(1, 0, param_6);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", setReceiveFileCallback__5SlinkPFiiPv_vPvPc);
/*void Slink::setReceiveFileCallback(void(*param_1)(int, int, void*),void *param_2,char *param_3) {
  this->field2_0x8 = param_3;
  this->field0_0x0 = param_1;
  this->field1_0x4 = param_2;
}*/

void Slink::enableCommunicationFlow(bool param_1) {
    Platform_ManualFlowControl(param_1);
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendName__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendVersion__5Slink);
/*void Slink::sendVersion() {
    uchar buffer[16];
    uchar* version = this->field0_0x0(this->field_0x34, this->field_0x20, this->field_0x24);
    buffer[0] = 0;
    int length = strlen((char*) version);
    sendCommand(0x82, '\0', length + 1);
    int lengthWithNullByte = length + 1;
    if (lengthWithNullByte != 0) {
        for (int i = 0; i < lengthWithNullByte; i++) {
            char currentChar = version[i];
            buffer[0] = currentChar ^ buffer[0];
        }
    }
    Platform_Write(version, lengthWithNullByte);
    Platform_Write(buffer, 1);
    Platform_WriteFlush();
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", updateItem__5SlinkPUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileBlock__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileAck__5SlinkUcUc);
/*long Slink::sendFileAck(uchar i, uchar param_2) {
    if (param_2 == 0x85) {
        FileAck* ack = &acks[i];
        if (++ack->field_1 <= ack->field_2) {
            return sendFileBlock(i);
        }
    } else {
        return printf("Retry block %d\n", acks[i].field_1);
    }
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", receiveFile__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", runFromDest__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", getFileHandle__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", responseFileExists__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendCommand__5SlinkUcUcUi);

int Slink::debugPrint(char* param_1) {
    return printf(param_1);
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", __8SlinkQuei);
/*SlinkQue::SlinkQue(int size) {
    this->size = size;
    this->buffer = new uchar[this->size];
    this->field2_0x8 = 0;
    this->field3_0xc = 0;
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", _$_8SlinkQue);
// Must be marked as virtual but errors with .gnu.linkonce
/*SlinkQue::~SlinkQue() {
    if (this->buffer != NULL) {
        delete[] this->buffer;
    }
}*/

int SlinkQue::SpaceAvailable() {
    int iVar1 = this->field3_0xc;
    int iVar2 = this->field2_0x8;
    if (iVar2 > iVar1) {
        return iVar2 - iVar1;
    }
    return (this->size - iVar1) + iVar2;
}

void SlinkQue::Put(uchar param_1) {
    int iVar1 = this->field3_0xc;
    this->buffer[iVar1] = param_1;
    iVar1++;
    this->field3_0xc = iVar1;
    if (this->size <= iVar1) {
        this->field3_0xc = 0;
    }
}

bool SlinkQue::IsEmpty() {
    return this->field3_0xc == this->field2_0x8;
}

// INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Take__8SlinkQue);
uchar SlinkQue::Take() {
    uchar value = this->buffer[this->field2_0x8++];
    if (this->size <= this->field2_0x8) {
        this->field2_0x8 = 0;
    }
    return value;
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", SpaceUsed__8SlinkQue);
/*int SlinkQue::SpaceUsed() {
    int spaceAvailable = SpaceAvailable();
    return this->size - spaceAvailable;
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Disconnect__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Write__5SlinkPUci);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_WriteFlush__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Read__5SlinkPUci);

void Slink::Platform_RunFromDest(int param_1) {
}

void* Slink::Platform_GetDefaultLoadAddr() {
    if (m_pFileBufferLoc == NULL) {
        m_pFileBufferLoc = new void*[0x19000 / sizeof(void*)];
    }
    return m_pFileBufferLoc;
}

void Slink::Platform_ManualFlowControl(bool param_1) {
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Init__5Slinki);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Reset__5Slink);

void Slink::Platform_Deinit() {
    Platform_Disconnect();
}
