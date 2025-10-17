#include "student.h"
#include <iostream>
#include <string>
#include "../unit/unit.h"
using namespace std;    

Student::Student(){
    first_name = "";
    last_name = "";
    studentID = 0;
    Enrolment_Type = 'U'; // Default to 'U' for undefined
}

Student::Student(string fn, string ln, long id){
    first_name = fn;
    last_name = ln;
    studentID = id;
    Enrolment_Type = 'U'; // Default to 'U' for undefined
}

string Student::getFirstName() {
    return first_name;
}

string Student::getLastName() {
    return last_name;
}

long Student::getStudentID() {
    return studentID;
}

char Student::getEnrolmentType() {
    return Enrolment_Type;
}

void Student::setFirstName(string fn) {
    first_name = fn;
}

void Student::setLastName(string ln) {
    last_name = ln;
}

void Student::setEnrolmentType(char type) {
    Enrolment_Type = type;
}

void Student::setStudentID(long id) {
    studentID = id;
}

void Student::ReportGrade() {
    cout << "There is no Grade Available" << endl;
}

double Student::GetOverallMark() {
    return 0.0;
}

string Student::getFinalGrade() {
    return "N/A";
}

bool Student::equals(Student other) {
        return (studentID == other.studentID);
    }
