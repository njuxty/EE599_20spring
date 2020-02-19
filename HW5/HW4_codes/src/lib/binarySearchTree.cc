#include "binarySearchTree.h"
#include <vector>

BST::BST() {
    root_ = nullptr;
}

BST::BST(std::vector<int> initial_values) {
    root_ = nullptr;
    for (int i = 0; i < initial_values.size(); i++) {
        this->push(initial_values.at(i));
    }
}

BST::~BST() {
    this->clear(root_);
}

void BST::push(int key) {
    if (root_ == nullptr) {
        root_ = new TreeNode(key);
    } else {
        TreeNode *p = root_;
        while (p != nullptr) {
            if (p->val == key) {
                return;
            } else if (p->val > key) {
                if (p->left == nullptr) p->left = new TreeNode(key);
                else p = p->left;
            } else {
                if (p->right == nullptr) p->right = new TreeNode(key);
                else p = p->right;
            }
        }
    }


}
bool BST::find(int key) {
    if (root_ == nullptr) return false;

    TreeNode *p = root_;
    while (p != nullptr) {
        if (key == p->val) {
            return true;
        } else if (key > p->val) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    return false;
}

bool BST::erase(int key) {
    if (root_ == nullptr) return false;

    int mark = 0;
    if (root_->val == key) mark = 1;
    TreeNode *p = root_;
    int left_right = 0;
    TreeNode *prev;
    while (p != nullptr) {
        if (key == p->val) {
            if (mark == 1) {
                prev = new TreeNode(1);
                prev->left = root_;
                prev->right = root_;
            }
            if (left_right == 0) {
                prev->left = this->pop(p);
                if(mark == 1) root_ = prev->left;
            } else {
                prev->right = this->pop(p);
                if(mark == 1) root_ = prev->right;
            }
            if (mark == 1) delete prev;
            return true;
        } else if (key > p->val) {
            prev = p;
            p = p->right;
            left_right = 1;
        } else {
            prev = p;
            p = p->left;
            left_right = 0;
        }
    }
    return false;
}

void BST::clear(TreeNode *node) {
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
    } else if (node->left == nullptr && node->right != nullptr) {
        this->clear(node->right);
        delete node;
    } else if (node->left != nullptr && node->right == nullptr) {
        this->clear(node->left);
        delete node;
    } else {
        this->clear(node->left);
        this->clear(node->right);
        delete node;
    }
}

std::vector<int> BST::print(){
    std::vector<int> v = {};
    this->printHelper(root_, v);
    return v;
}

void BST::printHelper(TreeNode *p, std::vector<int>& v) {
    if (p == nullptr) {
        return;
    }

    this->printHelper(p->left, v);
    v.push_back(p->val);
    this->printHelper(p->right, v);
}

int BST::popRightMin(TreeNode* p) {
    if (p->right->left == nullptr) {
        TreeNode* q = p->right;
        int temp = q->val;
        p->right = p->right->right;
        delete q;
        return temp;
    }

    p = p->right;
    while (p->left->left != nullptr) {
        p = p->left;
    }
    TreeNode* q = p->left;
    int temp = q->val;
    p->left = p->left->left;
    delete q;
    return temp;
}

TreeNode* BST::pop(TreeNode *p) {
    if (p->left == nullptr && p->right == nullptr) {
        delete p;
        return nullptr;
    } else if (p->left != nullptr && p->right == nullptr) {
        TreeNode *temp = p->left;
        delete p;
        return temp;
    } else if (p->left == nullptr && p->right != nullptr) {
        TreeNode *temp = p->right;
        delete p;
        return temp;
    } else {
        int temp = this->popRightMin(p);
        p->val = temp;
        return p;
    }
}

std::vector<int> BST::traverseByLevel() {
    std::vector<int> result;
    std::queue<TreeNode*> treeQueue;

    treeQueue.push(this->root_);
    while (!treeQueue.empty()) {
        TreeNode* node = treeQueue.front();
        if (node->left != nullptr) {
            treeQueue.push(node->left);
        }   
        if (node->right != nullptr) {
            treeQueue.push(node->right);
        }
        result.push_back(node->val);
        treeQueue.pop();
    }
    return result;
}