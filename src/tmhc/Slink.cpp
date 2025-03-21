#include <Slink.h>

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", __5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", _$_5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", init__5Slinki);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", deinit__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", update__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", isInitted__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", fileExists__5SlinkPcPFiiPv_vPv);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", writeFile__5SlinkPciiT1PFiiPv_vPv);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", readFile__5SlinkPciiT1PFiiPv_vPv);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", setReceiveFileCallback__5SlinkPFiiPv_vPvPc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", enableCommunicationFlow__5Slinkb);

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

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", _$_8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", SpaceAvailable__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Put__8SlinkQueUc);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", IsEmpty__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Take__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", SpaceUsed__8SlinkQue);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Disconnect__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Write__5SlinkPUci);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_WriteFlush__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Read__5SlinkPUci);

void Slink::Platform_RunFromDest(int param_1) {
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_GetDefaultLoadAddr__5Slink);

void Slink::Platform_ManualFlowControl(bool param_1) {
}

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Init__5Slinki);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Reset__5Slink);

INCLUDE_ASM("asm/nonmatchings/tmhc/Slink", Platform_Deinit__5Slink);
/*void Slink::Platform_Deinit() {
    Platform_Disconnect();
}*/
