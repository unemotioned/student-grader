// Copyright (c) 2025 UnEmotioneD

#include <vector>

#include "../include/print_info.h"
#include "../include/rank.h"
#include "../include/reader.h"
#include "../include/sort.h"
#include "../include/student.hpp"
#include "../include/terminal.hpp"

std::vector<Student> students;

int main() {
    clear_term();

    if (!read_students(students)) {
        return 1;
    }

    bubble_sort(students);
    std::cout << "Sorted high to low\n\n";

    assign_ranks(students);
    std::cout << "Ranks assigned\n\n";

    print_students_info(students);

    return 0;
}
