#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "../include/box_chars.hpp"
#include "../include/print.h"
#include "../include/student.hpp"

[[nodiscard]]
static std::vector<int>
calc_each_cells_width(const std::vector<Student> &students);
static std::string gen_table_head(const std::vector<int> &widths);
static std::string gen_row(const std::vector<int> &widths, const Student &s);
static std::string gen_table_hr(const std::vector<int> &widths);
static std::string gen_border_top(const std::vector<int> &widths);
static std::string gen_border_bot(const std::vector<int> &widths);

constexpr std::string_view th_num = "No.";
constexpr std::string_view th_name = "Name";
constexpr std::string_view th_kor = "Korean";
constexpr std::string_view th_eng = "English";
constexpr std::string_view th_math = "Math";
constexpr std::string_view th_tot = "Total";
constexpr std::string_view th_avg = "Average";
constexpr std::string_view th_grade = "Grade";
constexpr std::string_view th_rank = "Rank";

void print_table(const std::vector<Student> &students) {
    const std::vector<int> each_cells_width = calc_each_cells_width(students);

    std::cout << gen_border_top(each_cells_width) << '\n';
    std::cout << gen_table_head(each_cells_width) << '\n';
    std::cout << gen_table_hr(each_cells_width) << '\n';
    const std::string table_hr = gen_table_hr(each_cells_width);

    for (size_t i = 0; i < students.size(); i++) {
        std::cout << gen_row(each_cells_width, students[i]) << '\n';

        if (i != students.size() - 1) {
            std::cout << table_hr << '\n';
        }
    }

    std::cout << gen_border_bot(each_cells_width) << '\n';
}

std::string gen_row(const std::vector<int> &widths, const Student &s) {
    std::string grade;
    grade.push_back(s.get_grade());

    const std::string cells[] = {
        std::to_string(s.get_num()),    s.get_name(),
        std::to_string(s.get_kor()),    std::to_string(s.get_eng()),
        std::to_string(s.get_math()),   std::to_string(s.get_tot()),
        std::format("{}", s.get_avg()), grade,
        std::to_string(s.get_rank()),
    };

    const int cell_len[] = {
        static_cast<int>(std::to_string(s.get_num()).length()),
        static_cast<int>(s.get_name().size()),
        static_cast<int>(std::to_string(s.get_kor()).length()),
        static_cast<int>(std::to_string(s.get_eng()).length()),
        static_cast<int>(std::to_string(s.get_math()).length()),
        static_cast<int>(std::to_string(s.get_tot()).length()),
        static_cast<int>(std::format("{}", s.get_avg()).length()),
        1,
        static_cast<int>(std::to_string(s.get_rank()).length()),
    };

    std::string header{BOX_V};

    for (size_t j = 0; j < widths.size(); j++) {
        const int extra = widths[j] - cell_len[j];
        const int padding = extra / 2;
        const int remainder = extra % 2;

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

std::string gen_table_head(const std::vector<int> &widths) {
    constexpr std::string_view headers[] = {
        th_num, th_name, th_kor,   th_eng,  th_math,
        th_tot, th_avg,  th_grade, th_rank,
    };

    constexpr int header_lengths[] = {
        static_cast<int>(th_num.length()),  static_cast<int>(th_name.length()),
        static_cast<int>(th_kor.length()),  static_cast<int>(th_eng.length()),
        static_cast<int>(th_math.length()), static_cast<int>(th_tot.length()),
        static_cast<int>(th_avg.length()),  static_cast<int>(th_grade.length()),
        static_cast<int>(th_rank.length()),
    };

    std::string header{BOX_V};

    for (size_t j = 0; j < widths.size(); j++) {
        const int extra = widths[j] - header_lengths[j];
        const int padding = extra / 2;
        const int remainder = extra % 2;

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

std::string gen_table_hr(const std::vector<int> &widths) {
    std::string border_top{BOX_LT};

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

std::string gen_border_bot(const std::vector<int> &widths) {
    std::string border_top{BOX_BL};

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

std::string gen_border_top(const std::vector<int> &widths) {
    std::string border_top{BOX_TL};

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

std::vector<int> calc_each_cells_width(const std::vector<Student> &students) {
    const int num_len =
        static_cast<int>(std::to_string(students[0].get_num()).length());
    int name_len = th_name.length();
    int kor_len = th_kor.length();
    int eng_len = th_eng.length();
    int math_len = th_math.length();
    int tot_len = th_tot.length();
    int avg_len = th_avg.length();
    constexpr int grade_len = th_grade.length();
    int rank_len = th_rank.length();

    for (const Student &s : students) {
        const int s_name_len = static_cast<int>(s.get_name().length());
        const int s_kor_len =
            static_cast<int>(std::to_string(s.get_kor()).length());
        const int s_eng_len =
            static_cast<int>(std::to_string(s.get_eng()).length());
        const int s_math_len =
            static_cast<int>(std::to_string(s.get_math()).length());
        const int s_tot_len =
            static_cast<int>(std::to_string(s.get_tot()).length());
        const int s_avg_len =
            static_cast<int>(std::format("{}", s.get_avg()).length());
        const int s_rank_len =
            static_cast<int>(std::to_string(s.get_rank()).length());

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

    std::vector lengths = {num_len, name_len, kor_len,   eng_len, math_len,
                           tot_len, avg_len,  grade_len, rank_len};

    for (int &length : lengths) {
        constexpr int PAD = 2;
        length = length + PAD;
    }

    return lengths;
}
