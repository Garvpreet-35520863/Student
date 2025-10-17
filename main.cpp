/*
Title       : ICT167 Assignment 2
Author      : Garvpreet Singh
Date        : 15 October 2025
File Name   : ChangeC.h / ChangeC.cpp / main.cpp
Purpose     : Implements a program to calculate currency change for users in AED denominations.
Assumptions :
    1. Input data is in pre-defined required format.
    2. Marks are out of 100
    3. No input/output is done inside ChangeC class; all I/O handled by client program.
Expected Output:
    - Correct overallmark and pass grade with respect to student type.
    - Menu-driven output
*/

#include "function.h"
#include "student/student.h"
#include "student/student_course.h"
#include "student/student_research.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
int main() {
    vector<Student*> students = readStudents("student.txt");

    menu(students);

    for (auto s : students)
        delete s;
}
