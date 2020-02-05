#include "solution.h"

void Solution::swapByReference(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}
void Solution::swapByPointers(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

