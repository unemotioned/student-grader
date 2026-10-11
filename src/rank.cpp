#include <vector>

#include "../include/rank.h"
#include "../include/student.hpp"

void assign_ranks(std::vector<Student> &s) {
    // Competition ranking:
    // same score = same rank
    // next rank skips tied positions
    s[0].setRank(1);

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i - 1].getTot() == s[i].getTot()) {
            s[i].setRank(s[i - 1].getRank());
        } else {
            s[i].setRank(i + 1);
        }
    }
}
