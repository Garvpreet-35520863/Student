#include "unit.h"
#include <iostream>

using namespace std;

Unit::Unit() {
        enrolmentType = ' ';
        overallMark = 0.0;
        finalGrade = "N/A";
    }

double Unit::calculateOverallMark() {
    return overallMark;
}

string Unit::getFinalGrade() {
    return finalGrade;
}

char Unit::getEnrolmentType() {
    return enrolmentType;
}
