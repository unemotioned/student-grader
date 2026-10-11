#include <iostream>
#include <vector>

#include "../include/student.hpp"

void class_statistic(std::vector<Student> &students) {
    int kor_tot = 0;
    int eng_tot = 0;
    int math_tot = 0;
    float cnt = 0.0;

    for (Student &s : students) {
        kor_tot += s.getKor();
        eng_tot += s.getEng();
        math_tot += s.getMath();

        cnt += 1.0;
    }

    float kor_avg = (float)(kor_tot) / cnt;
    float eng_avg = (float)(eng_tot) / cnt;
    float math_avg = (float)(math_tot) / cnt;

    float class_avg = (kor_avg + eng_avg + math_avg) / 3.0;

    std::cout << "Korean  Avg: " << kor_avg << '\n';
    std::cout << "English Avg: " << eng_avg << '\n';
    std::cout << "Math    Avg: " << math_avg << '\n';
    std::cout << "Class   Avg: " << class_avg << '\n';
}
