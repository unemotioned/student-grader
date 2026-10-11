#include <vector>

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/config.hpp"
#include "../include/reader.h"
#include "../include/student.hpp"

bool read_students(std::vector<Student> &students) {
    std::ifstream ifs;
    bool is_read = false;

    try {
        ifs.open(STUDENTS_FILE);
        if (!ifs.is_open()) {
            throw std::runtime_error("Failed to open: " + STUDENTS_FILE);
        }

        int num, kor, eng, math;
        std::string name;

        std::string student_info;

        // each line from file to studentInfo
        while (getline(ifs, student_info)) {
            // parse line into student fields using string stream
            std::istringstream iss(student_info);
            iss >> num >> name >> kor >> eng >> math;

            // instantiate student object with arguments
            Student student(num, name, kor, eng, math);
            students.push_back(student); // adds student object to students list
            student_info = "";
        }
        ifs.close();

        if (students.empty()) {
            std::cerr << "Error: " << STUDENTS_FILE << " is empty.\n";
        } else {
            is_read = true;
            std::cout << "Successfully read: " << STUDENTS_FILE << "\n\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return is_read;
}
