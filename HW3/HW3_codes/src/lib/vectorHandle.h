#ifndef TEMPLATE_VECTOR_H
#define TEMPLATE_VECTOR_H

#include <vector>
#include <iostream>

// Q6
class VectorHandle {
public:
    VectorHandle(std::vector<int> v);
    void print();
    int handle(int n);

    int current;

private:
    std::vector<int> vec;
};

#endif