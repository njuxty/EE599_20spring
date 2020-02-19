#ifndef TEMPLATE_RECORD_H
#define TEMPLATE_RECORD_H

#include <iostream>

// Q5
class AcademicRecord {
public:
    AcademicRecord();
    AcademicRecord(int maths, int computers, int physics);
    AcademicRecord(const AcademicRecord& record);
    AcademicRecord operator++();
    AcademicRecord operator--();
    AcademicRecord operator++(int);
    AcademicRecord operator--(int);
    bool operator==(const AcademicRecord &record) const;
    AcademicRecord& operator+=(int increase);
    AcademicRecord& operator-=(int decrease);
    std::string print();

    int mathsGrade;
    int computersGrade;
    int physicsGrade;
};

#endif