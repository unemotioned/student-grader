#include <iostream>
#include <vector>

#include "../include/statistic.h"
#include "../include/student.hpp"

void class_statistic(const std::vector<Student> &students) {
    int kor_tot = 0;
    int eng_tot = 0;
    int math_tot = 0;
    float cnt = 0.0;

    for (const Student &s : students) {
        kor_tot += s.get_kor();
        eng_tot += s.get_eng();
        math_tot += s.get_math();

        cnt += 1.0;
    }

    const float kor_avg = static_cast<float>(kor_tot) / cnt;
    const float eng_avg = static_cast<float>(eng_tot) / cnt;
    const float math_avg = static_cast<float>(math_tot) / cnt;

    const auto class_avg =
        static_cast<float>((kor_avg + eng_avg + math_avg) / 3.0);

    std::cout << "Korean  Avg: " << kor_avg << '\n';
    std::cout << "English Avg: " << eng_avg << '\n';
    std::cout << "Math    Avg: " << math_avg << '\n';
    std::cout << "Class   Avg: " << class_avg << '\n';
}
