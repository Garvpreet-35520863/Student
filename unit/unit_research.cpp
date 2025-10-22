#include "unit_research.h"
#include <iostream>

using namespace std;

Unit_Research::Unit_Research() {
    dissertion_marks = 0.0;
    proposal_marks = 0.0;
}
Unit_Research::Unit_Research(char enrolType , float marks_d , float marks_p) {
    set_enroltype(enrolType);
    set_dissertion_marks(Unit::check_marks(marks_d));
    set_proposal_marks(Unit::check_marks(marks_p));
    set_overallmark(calculateOverallMark());
}
double Unit_Research::calculateOverallMark() {
    double marks = 0.0;
    marks = (dissertion_marks * 0.60) + (proposal_marks * 0.40);
    return marks;
}
void Unit_Research::set_dissertion_marks(float marks_d) {
    dissertion_marks = marks_d;
}
void Unit_Research::set_proposal_marks(float marks_p) {
    proposal_marks = marks_p;
}
