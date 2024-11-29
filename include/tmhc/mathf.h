#include <tmhc_common.h>

// Multiply operations
_fvector mathfMulVec(float a[3], _fvector b, _fvector c);

void mathfMulVec4x4(float a[3], _fvector b, _fvector c);
void mathfMulTransVecOld(float a[3], _fvector b, _fvector c);
void mathfMulTransVec4x4(float a[3], _fvector b, _fvector c);
void mathfMulTransVecFull4x4(float a[3], _fvector b, _fvector c);
void mathfMulMatrix(float a[3], float b[3], float c[3]);
void mathfMulMatrixTP(float a[3], float b[3], float c[3]);
void mathfMulMatrix3x3(float a[3], float b[3], float c[3]);
void mathfMulMatrixTP3x3(float a[3], float b[3], float c[3]);

// Add operations
void mathfAddMatrix3x3(float a[3], float b[3], float c[3]);
void mathfAddMatrixTP3x3(float a[3], float b[3], float c[3]);

// Sub operations
void mathfSubMatrix3x3(float a[3], float b[3], float c[3]);
void mathfSubMatrixTP3x3(float a[3], float b[3], float c[3]);

// Scale operations
void mathfScaleMatrix3x3(float a[3], float b[3], float scale);

// Other operations
void mathfVectorCrossUp(_fvector a, _fvector b);
void mathfVectorCrossRight(_fvector a, _fvector b);
void mathfPlaneTest(_plane plane, _fvector b);
void mathfNormalizeColumns(float a[3]);
void mathfTransposeMatrix(float a[3], float b[3]);

void mathfRotAxisToMatrix(float a[3], _fvector b);
void mathfRotAxisToMatrix(float a[3], _fvector b, float c, float d);

void mathfMatricesToRotAxis(_fvector a, float b[3], float c[3]);
void mathfMatrixToRotAxis(_fvector a, float b[3]);

void mathfCopyVectorNotAligned(_fvector a, _fvector b);
void mathfCopyMatrixNotAligned(float a[3], float b[3]);
void mathfCopyMatrixNoTrans(float a[3], float b[3]);

void mathfUnitMatrix(float a[3]);

void mathfRotMatrixMPH(float a[3], _fvector b);
void mathfRotMatrixPRH(float a[3], _fvector b);
void mathfRotMatrixRPHNoTrans(float a[3], _fvector b);

void mathfHPtoVector(_fvector a, float b, float c);

void mathfViewScreenMatrix(float a[3], float b[3], float c[3],
                           float d, float e, float f, float g,
                           float h, float i, float j, float k,
                           float l, float m, float n, float o);

void mathfDumpMatrix(float a[3]);

void mathfRPHFromMatrix(float a[3], _fvector b);
void mathfPRHFromMatrix(float a[3], _fvector b);

void mathfRotationFromPointToPoint(_fvector a, _fvector b, _fvector c);
void mathfMatrixFromPointToPoint(float a[3], _fvector b, _fvector c);
void mathfRotationFromVector(_fvector a, _fvector b);
float mathfHeadingFromPointToPoint(_fvector a, _fvector b);
float mathfHeadingFromVector(_fvector a);
float mathfPitchFromPointToPoint(_fvector a, _fvector b);
float mathfPitchFromVector(_fvector vec);

void mathfCartesianToSpherical(_fvector a, _fvector b);
void mathfCartesianToSpherical(_fvector a, _fvector b, _fvector c);
void mathfSphericalToCartesian(_fvector a, _fvector b);
void mathfSphericalToCartesian(_fvector a, _fvector b, _fvector c);

void mathfMatrixFromNormalAlignedY(float a[3], _fvector b);
void mathfMatrixFromNormalAlignedZ(float a[3], _fvector b);
void mathfDecomposeVector(_fvector a, _fvector b, _fvector c, _fvector d);
void mathfClosestApproach(_fvector a, _fvector b, _fvector c, _fvector d);
void mathfClosestApproach(_fvector a, _fvector b, _fvector c, _fvector d, float e, float f);
void mathfCatRomInit(float a[3][3], _fvector b, _fvector c, _fvector d, _fvector e);
void mathfCatRom(_fvector a, float b[3][3], float c);

void mathfOrthonormalize(float a[3]);
void mathfOrthonormalizeOverTime(float a[3], int time);

void mathfRandfND(float a, float b);
void mathfRandND(int a, int b);
void mathfRandf(float a, float b);
void mathfRand(int a, int b);

void mathfRandVector(_fvector a, float b);
void mathfRandInit(int a, int b);

void mathfRotAxisToQuaternion(_fvector a, _fvector b, float c);
void mathfRotAxisToQuaternion(_fvector a, _fvector b);

void mathfAxisAngleToQuaternion(_fvector a, _fvector b);
void mathfRotationArcQuaternion(_fvector a, _fvector b, _fvector c);
void mathfNormalizeQuaternion(_fvector a, _fvector b);
void mathfNormalizeQuaternionFromW(_fvector a, _fvector b);
void mathfConcatQuaternions(_fvector a, _fvector b, _fvector c);
void mathfDeConcatQuaternions(_fvector a, _fvector b, _fvector c);
void mathfQuaternionToUpVector(_fvector a, _fvector b);
void mathfQuaternionToForwardVector(_fvector a, _fvector b);
void mathfQuaternionToMatrix4x4(float a[3], _fvector b);
void mathfMatrixToQuaternion(_fvector a, float b[3]);
void mathfUnitizeQuaternion(_fvector a, _fvector b, float c);
void mathfQuaternionMulVec(_fvector a, _fvector b, _fvector c);
void mathfQuaternionMulTransVec(_fvector a, _fvector b, _fvector c);
void mathfSlerpQuaternion(_fvector a, _fvector b, _fvector c, float d);
void mathfVectorMinMaxGetMac(_fvector a, _fvector b);
void mathfFormatTime(int a, char *b);
void mathfFormatTimeMS(int a, char *b);
void mathfInCone(_fvector a, _fvector b);
void mathfIntLog2(unsigned int a);