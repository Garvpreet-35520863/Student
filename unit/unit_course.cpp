#include "unit_course.h"
#include <iostream>

using namespace std;

Unit_Course::Unit_Course() : Unit() {
    unitid = "";
    unit_level = 0;
    marks1 = 0.0;
    marks2 = 0.0;
    marks3 = 0.0;
    marks4 = 0.0;
    marks_final = 0.0;
}
Unit_Course::Unit_Course(string id, int level, char enrolType, float m1, float m2, float m3, float m4, float mFinal) : Unit() {
    unitid = id;
    unit_level = level;
    enrolmentType = enrolType;
    setMarks1(m1);
    setMarks2(m2);
    setMarks3(m3);
    setMarks4(m4);
    setMarksFinal(mFinal);
    overallMark = calculateOverallMark();
}
double Unit_Course::calculateOverallMark() {
        // Each assignment = 15% = 0.15 weight
        // Final exam = 40% = 0.40 weight
        overallMark = (marks1 * 0.15) + (marks2 * 0.15) + (marks3 * 0.15) + (marks4 * 0.15)
                      + (marks_final * 0.40);
    return overallMark;
}
string Unit_Course::setFinalGrade() {
    if (overallMark >= 80) {
        finalGrade = "HD";
    } else if (overallMark >= 70) {
        finalGrade = "D";
    } else if (overallMark >= 60) {
        finalGrade = "C";
    } else if (overallMark >= 50) {
        finalGrade = "P";
    } else {
        finalGrade = "N";
    }
    return finalGrade;
}

string Unit_Course::getUnitId() {
    return unitid;
}
int Unit_Course::getUnitLevel() {
    return unit_level;
}
void Unit_Course::setMarks1(float m1) {
    marks1 = m1;
}
void Unit_Course::setMarks2(float m2) {
	marks2 = m2;
}
void Unit_Course::setMarks3(float m3) {
	marks3 = m3;
}
void Unit_Course::setMarks4(float m4) {
	marks4 = m4;
}
void Unit_Course::setMarksFinal(float mFinal) {
	marks_final = mFinal;
}
