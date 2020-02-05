#include <iostream>
#include "src/lib/solution.h"
#include <vector>

int main()
{
    Solution solution ;
    std::vector<double> v = {637, 231, 123, 43, 69, 43, 900, 10, 7, 21, 99, 0, 500};
    double median = solution.rearrange(v);
    std::cout << median << std::endl;
    std::vector<double>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++) {
        std::cout << *iter << " ";
    }
    return EXIT_SUCCESS;
}