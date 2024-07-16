#include <iostream>
#include <mathf.h>

int main() {
  // Just to make GCC link my methods
  float a[] = {0, 0, 0};
  float b[] = {1, 2, 3};
  float c[] = {4, 5, 6};
  mathfAddMatrix3x3(a, b, c);

  std::cout << a[0] << a[1] << a[2] << std::endl;

  return 0;
}
