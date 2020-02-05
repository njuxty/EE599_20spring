#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::string str = "Kobe";
    std::cout << str << std::endl;
    solution.swapChar(str, 1, 2);
    std::cout << str << std::endl;
    solution.reverse(str);
    std::cout << str << std::endl;
    solution.lowerStr(str);
    std::cout << str << std::endl;
    solution.swapChar(str, 0, 10);
    std::cout << str << std::endl;
 
    return EXIT_SUCCESS;
}