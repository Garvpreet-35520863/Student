#include "unit_research.h"
#include <iostream>

using namespace std;

Unit_Research::Unit_Research() {
    dissertion_marks = 0.0;
    proposal_marks = 0.0;
}
Unit_Research::Unit_Research(char enrolType , float marks_d , float marks_p) {
    enrolmentType = enrolType;
    set_dissertion_marks(marks_d);
    set_proposal_marks(marks_p);
}
double Unit_Research::calculateOverallMark() {
    overallMark = (dissertion_marks * 0.60) + (proposal_marks * 0.40);
    return overallMark;
}
string Unit_Research::getFinalGrade() {
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
void Unit_Research::set_dissertion_marks(float marks_d) {
    dissertion_marks = marks_d;
}
void Unit_Research::set_proposal_marks(float marks_p) {
    proposal_marks = marks_p;
}
