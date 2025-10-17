#ifndef UNIT_RESEARCH_H
#define UNIT_RESEARCH_H

#include<iostream>
#include "unit.h"

using namespace std;

class Unit_Research : public Unit
{
private:

    float dissertion_marks ;
    float proposal_marks;

public:
    Unit_Research();
    Unit_Research(char enrolType , float marks_d , float marks_p);
    double calculateOverallMark() override;
    string getFinalGrade() override;
    void set_dissertion_marks(float marks_d);
    void set_proposal_marks(float marks_p);
};

#endif
