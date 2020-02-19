#include "maxHeap.h"
#include <vector>
#include <algorithm>
#include <iostream>

MaxHeap::MaxHeap() {
    data_ = {};
}

int MaxHeap::GetParentIndex(int i) {
    if (i == 0) {
        return -1;
    } 
    return (i - 1) / 2;
}

int MaxHeap::GetLeftIndex(int i) {
    if ((2 * i) + 1 >= data_.size()) {
        return -1;
    }
    return (2 * i) + 1;
}

int MaxHeap::GetRightIndex(int i) {
    if ((2 * i) + 2 >= data_.size()) {
        return -1;
    }
    return (2 * i) + 2;
}

int MaxHeap::GetBiggestChildIndex(int i) {
    if (this->GetLeftIndex(i) == -1 && this->GetRightIndex(i) == -1) {
        return -1;
    } else if (this->GetLeftIndex(i) == -1 && this->GetRightIndex(i) != -1) {
        return this->GetRightIndex(i);
    } else if (this->GetLeftIndex(i) != -1 && this->GetRightIndex(i) == -1) {
        return this->GetLeftIndex(i);
    } else {
        if (this->GetLeft(i) < this->GetRight(i)) {
            return this->GetRightIndex(i);
        } else return this->GetLeftIndex(i);
    }
}

int MaxHeap::GetLeft(int i) {
    if (this->GetLeftIndex(i) == -1) {
        return __INT_MAX__;
    }
    return data_[this->GetLeftIndex(i)];
}

int MaxHeap::GetRight(int i) {
    if (this->GetRightIndex(i) == -1) {
        return __INT_MAX__;
    }
    return data_[this->GetRightIndex(i)];
}

int MaxHeap::GetParent(int i) {
    if (this->GetParentIndex(i) == -1) {
        return __INT_MAX__;
    }
    return data_[this->GetParentIndex(i)];
}

int MaxHeap::top() {
    if (data_.size() == 0) {
        return __INT_MAX__;
    } else {
        return data_[0];
    }
}

void MaxHeap::push(int v) {
    data_.push_back(v);
    this->TrickleUp(data_.size() - 1);
}

void MaxHeap::pop() {
    if (data_.size() == 0) {
        std::cout << "Heap is empty! Can not pop!" << std::endl;
        return;
    }
    data_[0] = data_[data_.size()-1];
    data_.pop_back();
    this->TrickleDown(0);
}

void MaxHeap::TrickleUp(int i) {
    while (i != 0 && this->GetParent(i) < data_[i]) {
        std::swap(data_[i], data_[this->GetParentIndex(i)]);
        i = this->GetParentIndex(i);
    }
}
void MaxHeap::TrickleDown(int i) {
    while (i != -1 && data_[this->GetBiggestChildIndex(i)] > data_[i]) {
        int temp = this->GetBiggestChildIndex(i);
        std::swap(data_[i], data_[this->GetBiggestChildIndex(i)]);
        i = temp;
    }
}

std::vector<int> MaxHeap::testHelper() {
    return data_;
}