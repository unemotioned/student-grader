#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "../include/box_chars.hpp"
#include "../include/print.h"
#include "../include/student.hpp"

[[nodiscard]]
std::vector<int> calc_each_cells_width(std::vector<Student> &students);
std::string gen_table_head(std::vector<int> &widths);
std::string gen_row(std::vector<int> &widths, Student s);
std::string gen_table_hr(std::vector<int> &widths);
std::string gen_border_top(std::vector<int> &widths);
std::string gen_border_bot(std::vector<int> &widths);

const std::string TH_NUM = "No.";
const std::string TH_NAME = "Name";
const std::string TH_KOR = "Korean";
const std::string TH_ENG = "English";
const std::string TH_MATH = "Math";
const std::string TH_TOT = "Total";
const std::string TH_AVG = "Average";
const std::string TH_GRADE = "Grade";
const std::string TH_RANK = "Rank";

void print_table(std::vector<Student> &students) {
    std::vector<int> each_cells_width = calc_each_cells_width(students);

    std::cout << gen_border_top(each_cells_width) << '\n';
    std::cout << gen_table_head(each_cells_width) << '\n';
    std::cout << gen_table_hr(each_cells_width) << '\n';
    std::string table_hr = gen_table_hr(each_cells_width);

    for (size_t i = 0; i < students.size(); i++) {
        std::cout << gen_row(each_cells_width, students[i]) << '\n';

        if (i != students.size() - 1) {
            std::cout << table_hr << '\n';
        }
    }

    std::cout << gen_border_bot(each_cells_width) << '\n';
}

std::string gen_row(std::vector<int> &widths, Student s) {
    std::string grade;
    grade.push_back(s.getGrade());

    std::string cells[] = {
        std::to_string(s.getNum()),    s.getName(),
        std::to_string(s.getKor()),    std::to_string(s.getEng()),
        std::to_string(s.getMath()),   std::to_string(s.getTot()),
        std::format("{}", s.getAvg()), grade,
        std::to_string(s.getRank()),
    };

    int cell_len[] = {
        (int)std::to_string(s.getNum()).length(),
        (int)s.getName().size(),
        (int)std::to_string(s.getKor()).length(),
        (int)std::to_string(s.getEng()).length(),
        (int)std::to_string(s.getMath()).length(),
        (int)std::to_string(s.getTot()).length(),
        (int)std::format("{}", s.getAvg()).length(),
        1,
        (int)std::to_string(s.getRank()).length(),
    };

    std::string header = BOX_V;

    for (size_t j = 0; j < widths.size(); j++) {
        int extra = widths[j] - cell_len[j];
        int padding = (extra) / 2;
        int remainder = (extra) % 2;

        for (int k = 0; k < padding; k++) {
            header.append(" ");
        }
        header.append(cells[j]);
        for (int k = 0; k < padding + remainder; k++) {
            header.append(" ");
        }

        if (j != widths.size() - 1) {
            header.append(BOX_V);
        }
    }

    header.append(BOX_V);
    return header;
}

std::string gen_table_head(std::vector<int> &widths) {
    const std::string headers[] = {
        TH_NUM, TH_NAME, TH_KOR,   TH_ENG,  TH_MATH,
        TH_TOT, TH_AVG,  TH_GRADE, TH_RANK,
    };

    const int header_lengths[] = {
        (int)TH_NUM.length(), (int)TH_NAME.length(),  (int)TH_KOR.length(),
        (int)TH_ENG.length(), (int)TH_MATH.length(),  (int)TH_TOT.length(),
        (int)TH_AVG.length(), (int)TH_GRADE.length(), (int)TH_RANK.length(),
    };

    std::string header = BOX_V;

    for (size_t j = 0; j < widths.size(); j++) {
        int extra = widths[j] - header_lengths[j];
        int padding = (extra) / 2;
        int remainder = (extra) % 2;

        for (int k = 0; k < padding + remainder; k++) {
            header.append(" ");
        }
        header.append(headers[j]);
        for (int k = 0; k < padding; k++) {
            header.append(" ");
        }

        if (j != widths.size() - 1) {
            header.append(BOX_V);
        }
    }

    header.append(BOX_V);
    return header;
}

std::string gen_table_hr(std::vector<int> &widths) {
    std::string border_top = BOX_LT;

    for (size_t j = 0; j < widths.size(); j++) {
        for (int k = 0; k < widths[j]; k++) {
            border_top.append(BOX_H);
        }
        if (j < widths.size() - 1) {
            border_top.append(BOX_CR);
        }
    }

    border_top.append(BOX_RT);
    return border_top;
}

std::string gen_border_bot(std::vector<int> &widths) {
    std::string border_top = BOX_BL;

    for (size_t j = 0; j < widths.size(); j++) {
        for (int k = 0; k < widths[j]; k++) {
            border_top.append(BOX_H);
        }
        if (j < widths.size() - 1) {
            border_top.append(BOX_BT);
        }
    }

    border_top.append(BOX_BR);
    return border_top;
}

std::string gen_border_top(std::vector<int> &widths) {
    std::string border_top = BOX_TL;

    for (size_t j = 0; j < widths.size(); j++) {
        for (int k = 0; k < widths[j]; k++) {
            border_top.append(BOX_H);
        }
        if (j < widths.size() - 1) {
            border_top.append(BOX_TT);
        }
    }

    border_top.append(BOX_TR);
    return border_top;
}

std::vector<int> calc_each_cells_width(std::vector<Student> &students) {
    int num_len = std::to_string(students[0].getNum()).length();
    int name_len = TH_NAME.length();
    int kor_len = TH_KOR.length();
    int eng_len = TH_ENG.length();
    int math_len = TH_MATH.length();
    int tot_len = TH_TOT.length();
    int avg_len = TH_AVG.length();
    int grade_len = TH_GRADE.length();
    int rank_len = TH_RANK.length();

    for (Student &s : students) {
        int s_name_len = s.getName().size();
        int s_kor_len = std::to_string(s.getKor()).length();
        int s_eng_len = std::to_string(s.getEng()).length();
        int s_math_len = std::to_string(s.getMath()).length();
        int s_tot_len = std::to_string(s.getTot()).length();
        int s_avg_len = std::format("{}", s.getAvg()).length();
        int s_rank_len = std::to_string(s.getRank()).length();

        if (name_len < s_name_len) {
            name_len = s_name_len;
        }

        if (kor_len < s_kor_len) {
            kor_len = s_kor_len;
        }

        if (eng_len < s_eng_len) {
            eng_len = s_eng_len;
        }

        if (math_len < s_math_len) {
            math_len = s_math_len;
        }

        if (tot_len < s_tot_len) {
            tot_len = s_tot_len;
        }

        if (avg_len < s_avg_len) {
            avg_len = s_avg_len;
        }

        if (rank_len < s_rank_len) {
            rank_len = s_rank_len;
        }
    }

    std::vector<int> lengths = {num_len, name_len, kor_len,   eng_len, math_len,
                                tot_len, avg_len,  grade_len, rank_len};

    const int PAD = 2;
    for (size_t i = 0; i < lengths.size(); i++) {
        lengths[i] = lengths[i] + PAD;
    }

    return lengths;
}
