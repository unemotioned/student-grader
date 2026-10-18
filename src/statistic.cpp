#include <iostream>
#include <vector>

#include "../include/statistic.h"
#include "../include/student.hpp"

void class_statistic(const std::vector<Student> &students) {
    float kor_tot = 0.0;
    float eng_tot = 0.0;
    float math_tot = 0.0;
    float size = static_cast<float>(students.size());

    for (const Student &student : students) {
        kor_tot += student.get_kor();
        eng_tot += student.get_eng();
        math_tot += student.get_math();
    }

    const float kor_avg = kor_tot / size;
    const float eng_avg = eng_tot / size;
    const float math_avg = math_tot / size;

    const float class_avg = (kor_avg + eng_avg + math_avg) / 3.0;

    std::cout << "Korean  Avg: " << kor_avg << '\n';
    std::cout << "English Avg: " << eng_avg << '\n';
    std::cout << "Math    Avg: " << math_avg << '\n';
    std::cout << "Class   Avg: " << class_avg << '\n';
}
