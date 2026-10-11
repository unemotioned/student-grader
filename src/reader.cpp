#include <vector>

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/reader.h"
#include "../include/student.hpp"

std::vector<Student> read_students(const std::string file) {
    std::ifstream ifs;
    std::vector<Student> students;

    try {
        ifs.open(file);
        if (!ifs.is_open()) {
            throw std::runtime_error("Failed to open: " + file);
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
            std::cerr << "Error: " << file << " is empty.\n";
        } else {
            std::cout << "Successfully read: " << file << "\n\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return students;
}
