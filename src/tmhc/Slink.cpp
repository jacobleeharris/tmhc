#include <Slink.h>

extern void* m_pFileBufferLoc;

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

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", updateItem__5SlinkPUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileBlock__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendFileAck__5SlinkUcUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", receiveFile__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", runFromDest__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", getFileHandle__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", responseFileExists__5SlinkUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", sendCommand__5SlinkUcUcUi);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", debugPrint__5SlinkPc);
/*int debugPrint(char* param_1) {
    return printf(param_1);
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", __8SlinkQuei);
/*SlinkQue::SlinkQue(int size) {
    this->buffer = new uchar[size];
    this->size = size;
    this->field2_0x8 = 0;
    this->field3_0xc = 0;
}*/

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", _$_8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", SpaceAvailable__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Put__8SlinkQueUc);

bool SlinkQue::IsEmpty() {
    return this->field3_0xc == this->field2_0x8;
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Take__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", SpaceUsed__8SlinkQue);

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
