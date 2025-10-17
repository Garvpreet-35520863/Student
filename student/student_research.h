#ifndef STUDENT_RESEARCH_H
#define STUDENT_RESEARCH_H
#include "student.h"
#include "../unit/unit_research.h"
#include <iostream>

using namespace std;

class StudentResearch : public Student {
private:
    Unit_Research unit;
public:
    StudentResearch();
    StudentResearch(string fn, string ln, long id, char enrolType,
                    float marks_d, float marks_p);
    void ReportGrade();
    string getFinalGrade() override;
    double GetOverallMark() override;
    ~StudentResearch() override {}
};
#endif
