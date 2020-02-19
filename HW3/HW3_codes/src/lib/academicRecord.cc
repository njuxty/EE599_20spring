#include "academicRecord.h"
#include <algorithm>
#include <iostream>

AcademicRecord::AcademicRecord() {
    mathsGrade = 0;
    computersGrade = 0;
    physicsGrade = 0;
}

AcademicRecord::AcademicRecord(const AcademicRecord& record) {
    mathsGrade = record.mathsGrade;
    computersGrade = record.computersGrade;
    physicsGrade = record.physicsGrade;
}

AcademicRecord::AcademicRecord(int maths, int computers, int physics) {
    mathsGrade = maths;
    computersGrade = computers;
    physicsGrade = physics;
}

AcademicRecord AcademicRecord::operator++() {
    mathsGrade += 10;
    computersGrade += 10;
    physicsGrade += 10;
    mathsGrade = std::min<int>(mathsGrade, 100);
    computersGrade = std::min<int>(computersGrade, 100);
    physicsGrade = std::min<int>(physicsGrade, 100);
    return *this;
}

AcademicRecord AcademicRecord::operator--() {
    mathsGrade -= 20;
    computersGrade -= 20;
    physicsGrade -= 20;
    mathsGrade = std::max<int>(mathsGrade, 0);
    computersGrade = std::max<int>(computersGrade, 0);
    physicsGrade = std::max<int>(physicsGrade, 0);
    return *this;
}

AcademicRecord AcademicRecord::operator++(int) {
    AcademicRecord temp = *this;
    mathsGrade += 10;
    computersGrade += 10;
    physicsGrade += 10;
    mathsGrade = std::min<int>(mathsGrade, 100);
    computersGrade = std::min<int>(computersGrade, 100);
    physicsGrade = std::min<int>(physicsGrade, 100);
    return temp;
}

AcademicRecord AcademicRecord::operator--(int) {
    AcademicRecord temp = *this;
    mathsGrade -= 20;
    computersGrade -= 20;
    physicsGrade -= 20;
    mathsGrade = std::max<int>(mathsGrade, 0);
    computersGrade = std::max<int>(computersGrade, 0);
    physicsGrade = std::max<int>(physicsGrade, 0);
    return temp;
}

bool AcademicRecord::operator==(const AcademicRecord &record) const {
    return mathsGrade == record.mathsGrade && computersGrade == record.computersGrade && physicsGrade == record.physicsGrade;
}

AcademicRecord& AcademicRecord::operator+=(int increase) {
    mathsGrade += increase;
    computersGrade += increase;
    physicsGrade += increase;
    mathsGrade = std::min<int>(mathsGrade, 100);
    computersGrade = std::min<int>(computersGrade, 100);
    physicsGrade = std::min<int>(physicsGrade, 100);
    return *this;
}

AcademicRecord& AcademicRecord::operator-=(int decrease) {
    mathsGrade -= decrease;
    computersGrade -= decrease;
    physicsGrade -= decrease;
    mathsGrade = std::max<int>(mathsGrade, 0);
    computersGrade = std::max<int>(computersGrade, 0);
    physicsGrade = std::max<int>(physicsGrade, 0);
    return *this;
}

std::string AcademicRecord::print() {
    std::string result = "\n";
    result += "Maths: " + std::to_string(mathsGrade) + "\n";
    result += "Computers: " + std::to_string(computersGrade) + "\n";
    result += "Physics: " + std::to_string(physicsGrade);
    return result;
}