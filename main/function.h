/*
Title       : ICT167 Assignment 2
Author      : Garvpreet Singh
Date        : 15 October 2025
File Name   : main.cpp
Purpose     :  Read Data from a input file and Execute menu driven code
Assumptions :
    1. Input data is in pre-defined required format.
    2. Marks are out of 100
    3. No input/output is done inside class; all I/O handled by client program.
Expected Output:
    - Correct overallmark and pass grade with respect to student type.
    - Menu-driven output
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

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

// Function to read students from file
vector<Student*> readStudents(const string& filename);
//Function to remove Student
void remove_student(vector<Student*>& students);
//Fanction to calc Average
double Calculate_Average(const vector<Student*>& Students);
//Function to calc num of students above or brlow average
void Calculate_above_average(const vector<Student*>& students);
//Find student through id
void find_student(const vector<Student*>& students);
//Insertion sort
void sort_students_by_id(vector<Student*>& students);
//Write output
void Write_to_csv_file(const vector<Student*>& students , bool condition);
//Menu
void menu(vector<Student*>& students);

#endif /* FUNCTION_H_ */
