#ifndef UNIT_COURSE_H
#define UNIT_COURSE_H

#include "unit.h"
#include <iostream>

using namespace std;

class Unit_Course : public Unit {
private:
    string unitid;
    int unit_level;
    float marks1;
    float marks2;
    float marks3;
    float marks4;
    float marks_final;

public:
    Unit_Course();
    Unit_Course(string id, int level, char enrolType, float m1, float m2, float m3, float m4, float mFinal);
    double calculateOverallMark() override;
    //Setter For Final Grade
    string setFinalGrade();
    //Getter for UnitId
    string getUnitId();
    // Getter Unit level
    int getUnitLevel();
    // Setters for marks
    void setMarks1(float m1);
    void setMarks2(float m2);
    void setMarks3(float m3);
    void setMarks4(float m4);
    void setMarksFinal(float mFinal);
};
#endif
