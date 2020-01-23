#include "solution.h"

std::string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

int Solution::Factorial(int N) {
  if (N == 0) return 1;
  if (N < 0) return -1;

  int result = 1;
  for (int i = 1; i <= N; i ++) {
    result = result * i;
  }

  return result;

}

int Solution::FactorialRecursive(int N) {
  if (N == 0) return 1;
  if (N < 0) return -1;

  return N * FactorialRecursive(N-1);
}

