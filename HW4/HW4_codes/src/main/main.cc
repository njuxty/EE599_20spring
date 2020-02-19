#include <iostream>
#include <vector>
#include "src/lib/solution.h"
#include "src/lib/maxHeap.h"
#include "src/lib/binarySearchTree.h"

int main()
{
    std::cout << "***************************************************" << std::endl;
    
    // Q3
    std::cout << "Q3" << std::endl;
    std::vector<int> values  = {54, 5, 67, 22, 13, 100, 63, 43};
    BST tree = BST(values);
    tree.push(60);
    tree.erase(63);
    tree.erase(5);
    tree.erase(13);
    tree.push(57);
    tree.erase(67);
    tree.erase(54);
    std::vector<int> expected = {22, 43, 57, 60, 100};
    std::cout << (expected == tree.print()) <<std::endl;
    std::cout << "***************************************************" << std::endl;
    return EXIT_SUCCESS;
}