#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

// Q2
class MaxHeap {
public:
    MaxHeap(); // default constructor

    int GetParentIndex(int i); // *GT*
    int GetLeftIndex(int i); // *GT*
    int GetRightIndex(int i); // *GT*
    int GetBiggestChildIndex(int i); // *GT*

    int GetLeft(int i);
    int GetRight(int i);
    int GetParent(int i);

    int top(); // GT
    void push(int v); // GT
    void pop(); // GT
    void TrickleUp(int i);
    void TrickleDown(int i);

    std::vector<int> testHelper();

private:
    std::vector<int> data_;
};

#endif