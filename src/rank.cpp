#include <vector>

#include "../include/rank.h"
#include "../include/student.hpp"

void assign_ranks(std::vector<Student> &students) {
    // Competition ranking:
    // same score = same rank
    // next rank skips tied positions
    students[0].set_rank(1);

    for (size_t i = 1; i < students.size(); i++) {
        if (students[i - 1].get_tot() == students[i].get_tot()) {
            students[i].set_rank(students[i - 1].get_rank());
        } else {
            students[i].set_rank(static_cast<int>(i) + 1);
        }
    }
}
