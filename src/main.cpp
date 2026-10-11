// Copyright (c) 2025 UnEmotioneD

#include <vector>

#include "../include/config.hpp"
#include "../include/print.h"
#include "../include/rank.h"
#include "../include/reader.h"
#include "../include/sort.h"
#include "../include/statistic.h"
#include "../include/student.hpp"
#include "../include/terminal.hpp"

int main() {
    clear_term();

    std::vector<Student> students = read_students(STUDENTS_FILE);
    if (students.empty()) {
        return 1;
    }

    bubble_sort(students);
    std::cout << "Sorted high to low\n\n";

    assign_ranks(students);
    std::cout << "Ranks assigned\n\n";

    print_table(students);

    class_statistic(students);

    return 0;
}
