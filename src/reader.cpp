#include <vector>

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/reader.h"
#include "../include/student.hpp"

std::vector<Student> read_students(const std::string &file) {
    std::vector<Student> students;

    try {
        std::ifstream ifs;
        ifs.open(file);
        if (!ifs.is_open()) {
            throw std::runtime_error("Failed to open: " + file);
        }

        std::string student_info;
        // read each line from file and assign to student_info
        while (getline(ifs, student_info)) {
            int num = 0, kor = 0, eng = 0, math = 0;
            std::string name;

            // separate by space and assign to variables
            std::istringstream iss(student_info);
            iss >> num >> name >> kor >> eng >> math;

            Student student(num, name, kor, eng, math);
            students.push_back(student);
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
