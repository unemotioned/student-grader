#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "../include/box_chars.hpp"
#include "../include/print_info.h"
#include "../include/student.hpp"

// TODO: print into table format using border line characters
void print_students_info(std::vector<Student> &students) {
    std::string th_num = "No.";
    std::string th_name = "Name";
    std::string th_kor = "Korean";
    std::string th_eng = "English";
    std::string th_math = "Math";
    std::string th_tot = "Total";
    std::string th_avg = "Average";
    std::string th_grade = "Grade";
    std::string th_rank = "Rank";

    std::string table_header =
        std::format("{} | {} | {} | {} | {} | {} | {} | {} | {}", th_num, th_name,
               th_kor, th_eng, th_math, th_tot, th_avg, th_grade, th_rank);

    std::cout << table_header << '\n';

    // .length() return size_type
    for (std::size_t i = 0; i < table_header.length(); i++) {
        std::cout << BOX_H;
    }
    std::cout << '\n';

    for (Student &s : students) {
        std::string table_row =
            std::format("{} {} {} {} {} {} {} {} {}\n", s.num, s.name, s.kor,
                        s.eng, s.math, s.tot, s.avg, s.grade, s.rank

            );
        std::cout << table_row;
    }
}
