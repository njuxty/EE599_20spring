#include <iostream>
#include "src/lib/solution.h"

template<class T>
int findArraySize(T& arr) {
  return sizeof(arr) / sizeof(arr[0]);
}

int main()
{
    int arr1[] = {0, 1, 2, 3, 4, 5, 6};
    char arr2[] = {'k', 'o', 'b', 'e'};
    float arr3[] = {2.4};
    int arr4[] = {};
    std::cout << findArraySize(arr1) << std::endl;
    std::cout << findArraySize(arr2) << std::endl;
    std::cout << findArraySize(arr3) << std::endl;
    std::cout << findArraySize(arr4) << std::endl;
    return EXIT_SUCCESS;
}