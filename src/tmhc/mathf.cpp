#include <NotImplementedException.h>
#include <mathf.h>

void mathfAddMatrix3x3(float a[], float b[], float c[]) {
  for (int i = 0; i < 9; i++) {
    a[i] = b[i] + c[i];
  }
}
