#include <iostream>
#include <vector>
#include <algorithm>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;

    std::vector<int> v1 = {1, 2, 2, 3, 5, 6, 7, 7, 8};
    solution.removeDuplicates(v1);
    std::vector<int>::iterator it1;
    for (it1 = v1.begin(); it1 != v1.end(); it1++)
    {
        std::cout << *it1 << " ";
    }
    std::cout << std::endl;

    std::vector<int> v2 = {1, 2, 2, 3, 5, 6, 7, 7, 8};
    solution.reverse(v2);
    std::vector<int>::iterator it2;
    for (it2 = v2.begin(); it2 != v2.end(); it2++)
    {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;

    std::vector<int> v3 = {1, 2, 2, 3, 5, 6, 7, 7, 8};
    solution.removeOddNumbers(v3);
    std::vector<int>::iterator it3;
    for (it3 = v3.begin(); it3 != v3.end(); it3++)
    {
        std::cout << *it3 << " ";
    }
    std::cout << std::endl;

    std::vector<int> v4 = {1, 2, 3};
    std::vector<int> v5 = {1, 2, 3};
    std::vector<int> v6 = solution.concatenate(v4, v5);
    std::vector<int>::iterator it4;
    for (it4 = v6.begin(); it4 != v6.end(); it4++)
    {
        std::cout << *it4 << " ";
    }
    std::cout << std::endl;

    std::vector<int> v7 = {1, 2, 3};
    std::vector<int> v8 = {2, 2, 3, 4};
    std::vector<int> v9 = solution.unionValues(v7, v8);
    std::vector<int>::iterator it5;
    for (it5 = v9.begin(); it5 != v9.end(); it5++)
    {
        std::cout << *it5 << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}