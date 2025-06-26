#include <common.h>
#include <Slink.h>

class TMSlink : Slink
{
public:
    class TunerVals
    {
    public:
        TunerVals();

    private:
        int field3_0xc;
        int field6_0x18;
        int field14_0x38;
        int field15_0x3c;
        int field0_0x0;
        int field1_0x4;
        int field2_0x8;
        int field4_0x10;
        int field5_0x14;
        int field7_0x1c;
        int field8_0x20;
        int field9_0x24;
        int field10_0x28;
        int field11_0x2c;
        int field12_0x30;
        int field13_0x34;
    };

    TMSlink();
    ~TMSlink();

    void initSlink();
    void updateSlink();
    void stopSlink();
    void updateVolGroups();
    void initSFXVolRatios();
    void printSlinkInfo();

    // Virtual functions
    void **getMySlinkData(int *param_1);
    int getNumSlinkDataItems();
    uchar *getVersionString();
    int getElapsedMilliseconds();

private:
};
