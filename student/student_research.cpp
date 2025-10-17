#include "student_research.h"
#include "../unit/unit_research.h"
#include <iostream>

using namespace std;

StudentResearch::StudentResearch() : Student(), unit() {}

// using initializer list

// other option could to to set each value (for example unit.setmaeks1 = 1....)

StudentResearch::StudentResearch(string fn, string ln, long id, char enrolType,
                                 float marks_d, float marks_p)
    : Student(fn, ln, id),
      unit(enrolType, marks_d, marks_p) {
	Enrolment_Type = unit.getEnrolmentType();
}

double StudentResearch::GetOverallMark() {
    return unit.calculateOverallMark();
}

string StudentResearch::getFinalGrade() {
    return unit.getFinalGrade();
}

void StudentResearch::ReportGrade() {
    double overall = GetOverallMark();
    string grade = getFinalGrade();

    cout << getFirstName() << " " << getLastName()
         << " (ID: " << getStudentID() << ")\n"
         << "Enrollment Type: " << Enrolment_Type << "\n"
         << "Overall Mark: " << overall << "\n"
         << "Final Grade: " << grade << endl<<endl;
}
