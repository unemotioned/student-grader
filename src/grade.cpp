#include <iostream>
#include <math.h>
#include <vector>

#include "../include/grade.h"
#include "../include/student.h"

using std::cout;
using std::round;
using std::vector;

void grade_students(vector<Student> &students) {
    // use reference to modify original values
    for (Student &student : students) {
        student.tot = student.kor + student.eng + student.math;
        student.avg =
            round((static_cast<float>(student.tot) / 3.0f) * 100.0f) / 100.0f;

        // assign grades by avg score
        if (student.avg >= 90.0) {
            student.grade = 'A';
        } else if (student.avg >= 80.0) {
            student.grade = 'B';
        } else if (student.avg >= 70.0) {
            student.grade = 'C';
        } else if (student.avg >= 60.0) {
            student.grade = 'D';
        } else {
            student.grade = 'F';
        }
    }

    cout << "Grades assigned" << "\n\n";
}
