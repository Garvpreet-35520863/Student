#include "student_course.h"
#include "../unit/unit_course.h"

#include <iostream>
using namespace std;

// Default constructor
StudentCourse::StudentCourse() : Student(), unit() {}

// Parameterized constructor
// using initializer list

// other option could to to set each value (for example unit.setmaeks1 = 1....)
StudentCourse::StudentCourse(string fn, string ln, long id,
                             string unitId, int level, char enrolType,
                             float m1, float m2, float m3, float m4, float mFinal)
    : Student(fn, ln, id),
      unit(unitId, level, enrolType, m1, m2, m3, m4, mFinal)
	{
        Enrolment_Type = unit.getEnrolmentType();
}

// ReportGrade method
void StudentCourse::ReportGrade() {
    double overall = GetOverallMark();
    string grade = getFinalGrade();

    cout << getFirstName() << " " << getLastName()
         << " (ID: " << getStudentID() << ")\n"
         << "Enrollment Type: " << Enrolment_Type << "\n"
         << "Unit ID: " << unit.getUnitId() << "\n"
         << "Overall Mark: " << overall << "\n"
         << "Final Grade: " << grade << endl<<endl;
}

double StudentCourse::GetOverallMark() {
    return unit.calculateOverallMark();
}
string StudentCourse::getFinalGrade() {
    return unit.setFinalGrade();
}

