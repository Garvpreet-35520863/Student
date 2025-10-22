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

string read_item(stringstream& ss){
	string temp;
	getline(ss, temp, ',');
	return temp;
}

// Function to read students from file
vector<Student*> readStudents(const string& filename) {
    ifstream infile(filename);
    string line;
    vector<Student*> students;

    if (!infile) {
           cout << "File could not be opened.\n";
           return students;
       }

    //getline takes whole line as string, and then using sstream to assign values(similar to sscanf in c)
    while (getline(infile, line)) {

        stringstream ss(line); // getline only works on stream so line(string) converted to string stream.
        string type;

        type = read_item(ss); // Read first field (C or R)
        if (type.empty()) continue;

        // Course student
        if (tolower(type[0]) == 'c') {

            string first, last, unitId;
            long id;
            int level;
            float m1, m2, m3, m4, mFinal;

            first = read_item(ss);
            last = read_item(ss);


            string idStr;
            id = stol(read_item(ss)); //extracted string is converted to required value type
            unitId = read_item(ss);

            string levelStr; level = stoi(read_item(ss)); //extracted string is converted to required value type

            m1 = stof(read_item(ss));
            m2 = stof(read_item(ss));
            m3 = stof(read_item(ss));
            m4 = stof(read_item(ss));
            mFinal = stof(read_item(ss));

            //Since input file might have multiple entries, a temp pointer is created and checked with each student in vector and is only passed to vector if no equals found
            Student* new_student = new StudentCourse(first, last, id, unitId, level, type[0],
                    m1, m2, m3, m4, mFinal);
            bool duplicate_found = false;
            for(size_t i=0 ; i<(students.size()); i++){
                    	if(students[i]->equals(*new_student)){
                            cout<<"Duplicate Student found with ID: "<<students[i]->getStudentID()<<". Ignoring the new entry."<<endl;
                            delete new_student;
                            duplicate_found = true;
                            break;
                        }
                    }
            // if no duplicate pass to vector
            if(!duplicate_found){
            	students.push_back(new_student);
            }
        }
        else if (tolower(type[0]) == 'r') { // Research student
            string first, last;
            long id;
            float proposal, dissertation;

            first = read_item(ss);
            last = read_item(ss);
            id = stol(read_item(ss));

            proposal = stof(read_item(ss));
            dissertation = stof(read_item(ss));

            Student* new_student = new StudentResearch(first, last, id, type[0],dissertation, proposal);
            bool duplicate_found = false;
            for(size_t i=0 ; i<(students.size()); i++){
                    if(students[i]->equals(*new_student)){
                          cout<<"Duplicate Student found with ID: "<<students[i]->getStudentID()<<". Ignoring the new entry."<<endl;
                          delete new_student;
                          duplicate_found = true;
                          break;
                     }
                 }
           if(!duplicate_found){
               students.push_back(new_student);
            }
        }
        else{
        	cout << "Invalid student type '" << type << "' in input file. "
        	         << "Record skipped." << endl;
        	    continue; // skip this line and move to the next
        }
    }
    return students;
}

void remove_student(vector<Student*>& students){

    bool found = false;
	bool user_confirmation = false;
	long remove_id;
	// Don't remove until user gives confirmation
	while(!user_confirmation){
		long temp;
		int user_choice;
		do{
			cout << "Please enter id to remove"<< endl;
			cin >> temp;
			cout << "Are you Sure you want to remove: "<<temp<<" (Enter 1 to confirm or 0 to cancel)"<<endl;
			cin >> user_choice;
			if(user_choice != 1 && user_choice != 0){
							cout << "Enter valid choice"<<endl;}
		}while(user_choice != 1 && user_choice != 0);
			if (user_choice == 1){
				remove_id = temp;
				break;
			}
			else{
				continue;
			}
	}
	//loop through until desired student is reached
    for(size_t i=0 ; i<students.size() ; i++){
        if(students[i]->getStudentID() == remove_id){
        	delete students[i]; // delete memory
            students.erase(students.begin()+i); //remove from vector
            cout << "Student with ID " << remove_id << " has been removed." << endl << endl;
            found = true;
            break;
        }
    }
    // Negative Case
	if(!found){
		cout << "Student with ID " << remove_id << " not found." << endl;
	}
}

double Calculate_Average(const vector<Student*>& Students){

	double Total_overall_marks = 0.0;
    int Course_students = 0;
	for(size_t i=0 ; i<Students.size() ; i++){
        char enrol_type = tolower(Students[i]->getEnrolmentType());
		if(enrol_type == 'c'){ // only for coursework student
            Total_overall_marks += Students[i]->GetOverallMark();
            Course_students++;
        }
	}
    if (Course_students == 0){
         return 0.0; // Avoid division by zero
    }
    double b = Total_overall_marks / Course_students;
    cout << "The Average is: "<< b << endl;
    return (Total_overall_marks / Course_students);
}

void Calculate_above_average(const vector<Student*>& students){
	int Above_average = 0;
	int Below_average = 0;
    double Average = Calculate_Average(students);
    for(size_t i=0 ; i<students.size() ; i++){
    	char enrol_type = tolower(students[i]->getEnrolmentType());
        if(enrol_type == 'c'){
            if(students[i]->GetOverallMark() >= Average){
                Above_average++;
            }
            else{
                Below_average++;
            }
        }
}
    cout << "Average Overall Mark for Coursework Students: " << Average << endl;
    cout << "Number of Coursework Students Above Average: " << Above_average << endl;
    cout << "Number of Coursework Students Below Average: " << Below_average << endl<<endl;
}

void find_student(const vector<Student*>& students){
    long search_id;
    bool found = false;
    cout << "Enter Student ID to search: ";
    cin >> search_id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getStudentID() == search_id) {
            students[i]->ReportGrade();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << search_id << " not found." << endl;
    }
}

void sort_students_by_id(vector<Student*>& students){
	//Using insertion Sort
	for (size_t i = 1; i < students.size(); ++i) {
	    Student* keyPtr = students[i];
	    int j = i - 1;
	    while (j >= 0 && students[j]->getStudentID() > keyPtr->getStudentID()) {
	        students[j + 1] = students[j];
	        j--;
	    }
	    students[j + 1] = keyPtr;
	}

    cout << "Students sorted by Student ID." << endl;

    for (size_t i = 0; i < students.size(); i++)
    {
        cout << (i+1) << ". " << students[i]->getStudentID() << " - " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
    }
    cout << endl;
}

void Write_to_csv_file(const vector<Student*>& students , bool condition){
	//Must match assignment condition
	if (condition == false){
		cout<<"Task 6 needs to be performed for task 7 to execute"<<endl;
		cout<<"Returning to Main menu..."<<endl<<endl;
		return;
	}
	else{
		ofstream outputfile("output/output.csv");
		if(!outputfile){
			cout<<"Outputfile Couldn't be opened."<<endl;
			return;
		}
		cout<<"Writing Sorted Data to output file"<<endl;
		for (size_t i = 0; i < students.size(); i++)
		    {
				outputfile<<(i+1)<<". ";
		        outputfile<< students[i]->getEnrolmentType() <<" " << students[i]->getStudentID() << " - " << students[i]->getFirstName() << " " << students[i]->getLastName()<<endl<<"Overall Mark: " << students[i]->GetOverallMark() << " "<<"Final Grade: " << students[i]->getFinalGrade()  << endl<<endl;
		    }
	}
	cout<<"Data Saved to CSV file"<<endl;
	cout<<endl;
}

void menu(vector<Student*>& students){

    int choice;
    bool user_exit = false;
    bool six_happened = false;
	do{
		cout << "-----Menu-----" << endl;
		cout << "1. Quit (exit the program)" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Details of Student" << endl;
        cout << "4. Calculate Above Average Students(For Coursework students only)" << endl;
        cout << "5. Find Student by ID" << endl;
        cout << "6. Sort Students by Student Number" << endl;
        cout << "7. Save Sorted Data (need to perform 6 first)" << endl;

        cout << "Enter your choice(1-7): ";
        cin >> choice;
        cout <<endl;
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                // Quit
                cout << "Exiting program." << endl;
                user_exit = true;
                break;
            case 2:
                // Remove Student
            	remove_student(students);
            	break;
            case 3:
            	for (auto s : students)
            	        s->ReportGrade();
                break;
            case 4:
                // Calculate Above Average Students
            	Calculate_above_average(students);
				break;
            case 5:
                // Find Student by ID
                find_student(students);
                break;
            case 6:
                // Sort Students by Student Number
                sort_students_by_id(students);
                six_happened = true;
                break;
            case 7:
            	//output
            	Write_to_csv_file(students , six_happened);
                break;
            }
        }

	}while(!user_exit); // loop until user_exit = true
}
