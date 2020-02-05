#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    int a = 8;
    int b = 24;
    std::cout << "a: " << a << " b: " << b << std::endl;
    solution.swapByReference(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    solution.swapByPointers(&a, &b);
    std::cout << "a: " << a << " b: " << b << std::endl;

    return EXIT_SUCCESS;
}