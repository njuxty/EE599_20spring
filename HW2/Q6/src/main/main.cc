#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::string str1 = "KobeByrant";
    std::string str2 = "Kobe8eboK";
    std::string str3 = "!@#$%^&*()";
    std::string str4 = "A man, a plan, a canal, Panama!";
    std::cout << solution.simplePalindrome(str1) << std::endl;
    std::cout << solution.simplePalindrome(str2) << std::endl;
    std::cout << solution.approximatePalindrome(str3) << std::endl;
    std::cout << solution.approximatePalindrome(str4) << std::endl;
    return EXIT_SUCCESS;
}