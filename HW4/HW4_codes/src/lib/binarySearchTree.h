#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <queue>

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
    BST();

    // Inserts elements of initial_values
    // one by one into the Tree
    BST(std::vector<int> initial_values);
    ~BST();

    void push(int key); // **GT** Inserts a key inside Tree
    bool find(int key); // **GT** Returns true of key is in the tree
    bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.

    void clear(TreeNode *node);
    std::vector<int> print();
    void printHelper(TreeNode *p, std::vector<int>& v);
    int popRightMin(TreeNode* p);
    TreeNode* pop(TreeNode *p);

    std::vector<int> traverseByLevel();

private:
    TreeNode *root_;
};

#endif