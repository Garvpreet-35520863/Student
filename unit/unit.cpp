#include "unit.h"
#include <iostream>

using namespace std;

Unit::Unit() {
		set_enroltype(' ');
        set_overallmark(0.0);
        set_FinalGrade("N/A");
    }

double Unit::calculateOverallMark() {
    return overallMark;
}

void Unit::set_enroltype(char etype){
	enrolmentType = etype;
}

void Unit::set_overallmark(double Omark){
	overallMark = Omark;
}

void Unit::set_FinalGrade(string fgrade){
	finalGrade = fgrade;
}

double Unit::get_overallmark() {
	return overallMark;
}

string Unit::getFinalGrade() {
	if (overallMark >= 80) {
	        finalGrade = "HD";
	    } else if (overallMark >= 70) {
	        finalGrade = "D";
	    } else if (overallMark >= 60) {
	        finalGrade = "C";
	    } else if (overallMark >= 50) {
	        finalGrade = "P";
	    } else {
	        finalGrade = "N";
	    }
	    return finalGrade;
}

char Unit::getEnrolmentType() {
    return enrolmentType;
}

// check if mark is between 1-100
float Unit::check_marks(float temp_marks){
	if(temp_marks >= 0 && temp_marks<= 100){
		return temp_marks;
	}
	else{
		cout << "Invalid Marks, setting to 0"<<endl;
	}
	return 0.0;
}
