/*
Title       : ICT167 Assignment 2
Author      : Garvpreet Singh
Date        : 15 October 2025
File Name   : main.cpp
Purpose     : Read Data from a input file and Execute menu driven code
Assumptions :
    1. Input data is in pre-defined required format.
    2. Marks are out of 100
    3. No input/output is done inside class; all I/O handled by client program.
Expected Output:
    - Correct overallmark and pass grade with respect to student type.
    - Menu-driven output
*/

#include "function.h"
#include "../student/student.h"
#include "../student/student_course.h"
#include "../student/student_research.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
int main() {
	//creating a vector of pointer to maintaon condition for polymorphism
	string filename;
	cout << "Enter input filename: (in the format -> folder/file)"<< endl;
	cin >> filename;

    vector<Student*> students = readStudents(filename);

    if(students.empty()){
    	cout<<"No data to present"<<endl;
    	cout<<"Exiting..."<<endl;
    	return 0;
    }

    menu(students);
    //freeing the memory
    for (auto s : students)
        delete s;
}
