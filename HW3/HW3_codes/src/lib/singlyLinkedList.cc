#include "singlyLinkedList.h"
#include <iostream>
#include <unordered_set>

// Q3
SinglyLinkedList::SinglyLinkedList() {
    head_ = new ListNode(NULL);
}

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &inputs, int i) {
    ListNode *p;
    ListNode *ii;

    if (inputs.size() == 0) {
        head_ = new ListNode(NULL);
    } else {
        p = new ListNode(inputs[0]);
        head_ = new ListNode(NULL);
        head_->next = p;
    }

    if (i == 1) {
        ii = p;
    }

    for (int j = 1; j < inputs.size(); j += 1) {
        p->next = new ListNode(inputs[j]);
        p = p->next;
        if (i == j + 1) ii = p;
    }

    if (i > 0 && i <= inputs.size()) {
        p->next = ii;
    }
}

SinglyLinkedList::~SinglyLinkedList() {
    std::unordered_set<ListNode *> hashset;
    ListNode *q = head_;
    while (hashset.find(q->next) == hashset.end() && q->next != nullptr) {
        hashset.insert(q);
        q = q->next;
    }
    q->next = nullptr;

    ListNode *p;
    while (head_->next != nullptr) {
        p = head_;
        head_ = head_->next;
        delete p;
    }
    delete head_;
}

bool SinglyLinkedList::empty() {
    return head_->next == nullptr;
}

int SinglyLinkedList::size() {
    ListNode *p = head_->next;
    int ssize = 0;
    while (p != nullptr) {
        ssize += 1;
        p = p->next;
    }
    return ssize;
}

void SinglyLinkedList::push_back(int i) {
    if (this->empty()) {
        ListNode *p = new ListNode(i);
        head_->next = p;
    } else {
        ListNode *p = this->GetBackPointer();
        p->next = new ListNode(i);
    }
}

void SinglyLinkedList::push_front(int i) {
    if (this->empty()) {
        ListNode *p = new ListNode(i);
        head_->next = p;
    } else {
        ListNode *p = new ListNode(i);
        p->next = head_->next;
        head_->next = p;
    } 
}
void SinglyLinkedList::insert_after(ListNode* p, int i) {
    ListNode *q = new ListNode(i);
    q->next = p->next;
    p->next = q;
}

void SinglyLinkedList::erase(ListNode* p) {
    ListNode *q;
    q = head_;
    while (q->next != p) {
        q = q->next;
    }
    q->next = p->next;
    delete p;
}

void SinglyLinkedList::pop_front() {
    if (this->empty()) return;
    ListNode *p;
    p = head_->next;
    head_->next = p->next;
    delete p;
}

void SinglyLinkedList::pop_back() {
    if (this->empty()) return;
    ListNode *p = head_;
    while (p->next->next != nullptr) {
        p = p->next;
    }
    ListNode *q = p->next;
    p->next = nullptr;
    delete q;
}

int SinglyLinkedList::back() {
    if (this->empty()) {
        std::cout << "Empty!" << std::endl;
        return 0;
    }
    return this->GetBackPointer()->val;
}

int SinglyLinkedList::front() {
    if (this->empty()) {
        std::cout << "Empty!" << std::endl;
        return 0;
    }
    return head_->next->val;
}

ListNode *SinglyLinkedList::GetBackPointer() {
    if (this->empty()) {
        return nullptr;
    }

    ListNode *p = head_;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}

ListNode *SinglyLinkedList::GetIthPointer(int i) {
    if (this->empty() || i > this->size()) {
        return nullptr;
    }

    ListNode *p = head_;
    for (int j = 0; j < i; j += 1) {
        p = p->next;
    }
    return p;
}

void SinglyLinkedList::print() {
    if (this->empty()) std::cout << "Empty list: {}." << std::endl;
    else {
        ListNode *p = head_->next;
        std::cout << "List with items: {";
        while (p != nullptr) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << "}.";
    }
}