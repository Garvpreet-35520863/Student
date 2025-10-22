#ifndef UNIT_H
#define UNIT_H

#include<iostream>

using namespace std;

class Unit {
private:
    char enrolmentType;        // 'C' or 'R'
    double overallMark;        // calculated overall mark
    string finalGrade;    // final grade

public:
    Unit();

    virtual double calculateOverallMark();

    void set_enroltype(char etype);

    void set_overallmark(double Omark);

    void set_FinalGrade(string fgrade);

    double get_overallmark();

    string getFinalGrade();

    char getEnrolmentType();

    // check if mark is between 1-100
    float check_marks(float temp_marks);

    virtual ~Unit() {}
};
#endif
