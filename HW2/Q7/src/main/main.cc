#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::string str1 = "Kobe24Kobe";
    std::string str2 = "Byrant";
    std::map<char, char> result = solution.mappable(str1, str2);
    typedef std::map<char, char>::iterator MyIterator;
    MyIterator iter;
    for(iter = result.begin(); iter != result.end(); iter++) {
        std::cout << iter->first << ' ' << iter->second << std::endl;
    }
    return EXIT_SUCCESS;
}