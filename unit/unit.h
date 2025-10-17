#ifndef UNIT_H
#define UNIT_H

#include<iostream>

using namespace std;

class Unit {
protected:
    char enrolmentType;        // 'C' or 'R'
    double overallMark;        // calculated overall mark
    string finalGrade;    // final grade

public:
    Unit();

    virtual double calculateOverallMark();

    virtual string getFinalGrade();

    char getEnrolmentType();

    virtual ~Unit() {}
};
#endif
