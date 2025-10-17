#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include "student.h"
#include"../unit/unit_course.h"
#include<iostream>

using namespace std;

class StudentCourse : public Student{
    private:
        Unit_Course unit;
    public:
        // Constructor
        StudentCourse();
        // Parameterized Constructor
        StudentCourse(string fn, string ln, long id, 
                  string unitId, int level, char enrolType,
                  float m1, float m2, float m3, float m4, float mFinal);

        void ReportGrade() override;
        double GetOverallMark() override;
        string getFinalGrade() override;
        ~StudentCourse() override {}

};
#endif
