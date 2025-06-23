#include <common.h>

class ActHead;
class Destructible;
struct _hierScript;

class ActionMgr
{
    void initOnBoot();
    void initGenericEvent(void(uint param_1, _fvector param_2));
    void freeAll();
    void startAction(ActHead *param_1, float *param_2, _fvector *param_3, Destructible *param_4);
    void startAction(ActHead *param_1, ActionContext *ctx);
    void startActionAtEnd(ActHead *param_1, float *param_2, _fvector *param_3, Destructible *param_4);
    void updateTick();
    long createActionClass(ActHead *param_1, ActionContext *ctx);
    void cacheScript(_hierScript script);
    void callScriptFromId(ushort param_1, ushort param_2, ActionContext *ctx);
    void finishAllActions();

    // Check return type on the following methods:
    long allocateAction();
    long getAction(int idx);

    void freeAction(Action *action);

    ActionContext *allocateContext();
    void freeContext(ActionContext *ctx);
};

class ActionContext
{
public:
    void init(ActionMgr *mgr, float *param_2, _fvector *param_3, Destructible *param_4);
    ActionContext &operator=(const ActionContext &other);

private:
    ActionMgr *mgr;
};

class Action
{
    Action(ActHead *param_1, ActionContext *ctx);
    long startTask();

    // Check return type
    int getActHead();
};

// Check return types on following methods:
// These methods return an undefined8

long doGroup(Action *action);
long doTransform(Action *action);
long doAnimation(Action *action);
long doDebris(Action *action);
long doSound(Action *action);
long doCamShake(Action *action);
long doDomino(Action *action);
long doUnsupported(Action *action);
long doRunScript(Action *action);
long doGenericEvent(Action *action);
