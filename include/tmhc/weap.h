#include <Car.h>
#include <CarWeap.h>
#include <Interactive.h>
#include <common.h>

class WeaponConfig {

};

class Weapons {
  public:
    void preParseForGame();
    void postParseForGame();
    void shutDown();
    void updateWeapons();
    void CreateNetWeapon(int param_1, Interactive *param_2, Interactive *param_3, CarWeap *param_4, _fvector *param_5,
                         _fvector *param_6, _fvector *param_7, short param_8);
    void CreateWeapon(int param_1, Interactive *param_2, Interactive *param_3, CarWeap *param_4, _fvector *param_5,
                      _fvector *param_6, _fvector *param_7, short param_8);
    void addEpNode(int param_1, _hierhead *param_2);
};

class Weapon {
  public:
    void initWeapon(int param_1, Interactive *param_2, Interactive *param_3, CarWeap *param_4, _fvector *param_5,
                    _fvector *param_6, _fvector *param_7);
    void updateRotation();
    void updateNoLock();
    void updateLockOn();
    void updateLockAhead();
    void updateLock(_fvector &param_1);
    void updateLockHeading(_fvector &param_1);
    void updateLockPitch(_fvector &param_1);
    void updateErraticity();
    void updateTranslation();
    void updateTerrainFollowing();
    void smoothPitchToGround(_fvector *param_1);
    void updateGasCanTrans();
    void updateRicoTrans();
    void dropWeaponFromTrajectory();
    void NetDropWeaponFromTrajectory();
    void weaponHD();
    void spectreHD();
    void gasCanHD();
    void ricoHD();
    void freezeHD();
    void detonate(HdResult *param_1, int param_2);
    undefined4 checkBlastRadius(HdResult *param_1);
    undefined4 handleDestructionRelic(float param_1);
    void killWeapon();
    void checkIgnoreHit(HdResult *param_1);
    void computeReflection2D(_fvector *param_1, _fvector *param_2);
    void computeReflection(_fvector *param_1, _fvector *param_2);
    void initGasCan();
    void updateTurnRedReticle();
    undefined4 reflectionRelicCarHit(Car *param_1, HdResult *param_2);
};
