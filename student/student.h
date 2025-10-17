#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "../unit/unit.h"

using namespace std;

class Student {
	// Private Members
private:
    string first_name;
    string last_name;
    long studentID;

protected:char Enrolment_Type; // Needs to be changed

public:
    // Constructor
    Student();
    // Parameterized Constructor
    Student(string fn, string ln, long id);

    // Getter for First Name
    string getFirstName();

    // Getter for Last Name
    string getLastName();

    // Getter for Student ID
    long getStudentID();

    // Setter for First Name
    void setFirstName(string fn);


    // Setter for Last Name
    void setLastName(string ln);

    void setEnrolmentType(char type);
    
    // Getter for Enrollment Type
    char getEnrolmentType();

    // Getter for Final Grade
    virtual string getFinalGrade();

    // Setter for Student ID
    void setStudentID(long id);

    //Getter for Overall Mark
    virtual double GetOverallMark();

    virtual void ReportGrade();

    bool equals(Student other);

    //destructor
    virtual ~Student() {}
};

#endif
