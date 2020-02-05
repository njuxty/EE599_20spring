#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::cout << solution.add(33583, 60) << std::endl;
    std::cout << solution.add(33583, 2147483646) << std::endl;
    std::cout << solution.add("Kobe", "Byrant") << std::endl;
    std::cout << solution.add("", "") << std::endl;
    std::cout << solution.add(24, "Kobe") << std::endl;
    std::cout << solution.add("Kobe", 8) << std::endl;

    return EXIT_SUCCESS;
}