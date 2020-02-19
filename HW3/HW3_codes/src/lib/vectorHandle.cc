#include "vectorHandle.h"

VectorHandle::VectorHandle(std::vector<int> v) {
    vec = v;
    current = 0;
    this->print();
}

void VectorHandle::print() {
    std::cout << "***********************************************************" << std::endl;
    std::cout << "Vector:";
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "Please choose any of the following options:" << std::endl;
    std::cout << "1. What is the first element?" << std::endl;
    std::cout << "2. What is the last element?" << std::endl;
    std::cout << "3. What is the current element?" << std::endl;
    std::cout << "4. What is the ith element from the current location?" << std::endl;
    std::cout << "5. Exit." << std::endl;
    std::cout << "***********************************************************" << std::endl;
}

int VectorHandle::handle(int n) {
    std::vector<int>::iterator it;
    if (n == 1) {
        it = vec.begin();
        std::cout << "Output: " << *it << std::endl;
        current = 0;
    } else if (n == 2) {
        it = vec.end();
        it--;
        std::cout << "Output: " << *it << std::endl;
        current = it - vec.begin();
    } else if (n == 3) {
        it = vec.begin();
        it += current;
        std::cout << "Output: " << *it << std::endl;
    } else if (n == 4) {
        int index;
        std::cout << "Enter the value of i: " << std::endl;
        std::cin >> index;
        if (index < 0) {
            std::cout << "Value of i cannot be negative." << std::endl;
        } else {
            if (index + current >= vec.end() - vec.begin()) {
                std::cout << "Sorry! You cannot traverse " << index << " elements from your current location." << std::endl;
            } else {
                it = vec.begin();
                current += index;
                it += current;
                std::cout << "Output: " << *it << std::endl;
            }
        }
    } else if (n == 5) {
        std::cout << "Exit!" << std::endl;
        return 1;
    } else {
        std::cout << "Please enter effective number!" << std::endl;
    }

    this->print();
    return 0;
}
