#include <common.h>

class DrawContext;

class Widget {

};

class Base : Widget {
private:
    char field0_0x0;
    // Flag
    char field_0x1;
    // Unknown flag
    char field2_0x2;
    // Hide flag
    char field3_0x3;
public:
    void update();
    void draw(DrawContext* ctx);
    void parseMessage(int param_1, uint param_2);
    void parseDbNode(_hierhead* param_1, _hierhead* param_2);
    void setFlag(uchar param_1, bool param_2);
    bool getFlag(uchar param_1);
    void disableAndHide();
    void addHideFlag(uchar param_1, bool param_2);
    void removeHideFlag(uchar param_1);
    bool isHiddenByFlags();
};

class Text : Widget {
private:

public:
    Text(ushort param_1, ushort param_2, ushort param_3);
    void parseMessage(int param_1, uint param_2);
    void draw(Base* base, DrawContext* ctx);

};
