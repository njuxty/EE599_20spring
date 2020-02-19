#include <iostream>
#include <vector>
#include "src/lib/solution.h"
#include "src/lib/singlyLinkedList.h"
#include "src/lib/academicRecord.h"
#include "src/lib/vectorHandle.h"

int main()
{
    Solution solution ;

    // Q3
    std::cout << "Q3" << std::endl;
    SinglyLinkedList linkedList = SinglyLinkedList();
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(6);
    ListNode *p = linkedList.GetBackPointer();
    ListNode *q = linkedList.GetIthPointer(3);
    linkedList.insert_after(p, 7);
    linkedList.insert_after(q,5);
    linkedList.push_front(1);
    linkedList.print();
    std::cout << "Is list empty? " << linkedList.empty() << std::endl;
    std::cout << "List size: " << linkedList.size() << std::endl;
    linkedList.pop_back();
    linkedList.pop_front();
    linkedList.print();
    std::cout << "Is list empty? " << linkedList.empty() << std::endl;
    std::cout << "List size: " << linkedList.size() << std::endl;
    linkedList.erase(q);
    linkedList.print();
    std::cout << "Is list empty? " << linkedList.empty() << std::endl;
    std::cout << "List size: " << linkedList.size() << std::endl;
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.print();
    std::cout << "Is list empty? " << linkedList.empty() << std::endl;
    std::cout << "List size: " << linkedList.size() << std::endl;
    std::vector<int> vec = {1, 2, 3};
    SinglyLinkedList linkedList1 = SinglyLinkedList(vec, 1);
    ListNode *ptr = linkedList1.head_->next->next->next;
    std::cout << ptr->next->val << std::endl;
    std::cout << std::endl;

    // Q4
    std::cout << "Q4" << std::endl;
    std::string str = "(a+b)[c*d]{5g+h}";
    std::cout << solution.isValidBrackets(str) << std::endl;
    std::cout << std::endl;

    // Q5
    std::cout << "Q5" << std::endl;
    AcademicRecord obj1, obj2;
    obj1.mathsGrade = 5;
    obj1.computersGrade = 10;
    obj1.physicsGrade = 95;
    std::cout<< "Value before incrementation: " << obj1.print() << std::endl;
    obj1++;
    std::cout<< "Value after incrementation: " << obj1.print() << std::endl;
    obj1--;
    std::cout<< "Value after decrementation: " << obj1.print() << std::endl;
    obj2 == obj1;
    std::cout<< "Value of Object 2: " << obj2.print() << std::endl;
    obj2 += 50;
    std::cout << "Value of Object 2 after increasing marks by 50 for each subject: " << obj2.print() << std::endl;
    obj2 -= 30;
    std::cout << "Value of Object 2 after decreasing marks by 30 for each subject: " << obj2.print() << std::endl;
    std::cout << std::endl;

    // Q6
    std::vector<int> v = {1, 4, 5, 23, 100, 12, 18, 175};
    VectorHandle handler = VectorHandle(v);
    int input;
    std::cin >> input;
    while (handler.handle(input) != 1) {
        std::cin >> input;
    }

    return EXIT_SUCCESS;
}