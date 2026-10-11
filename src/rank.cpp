#include <vector>

#include "../include/rank.h"
#include "../include/student.hpp"

void assign_ranks(std::vector<Student> &s) {
    int size = s.size();

    // Competition ranking:
    // same score = same rank
    // next rank skips tied positions
    s[0].setRank(1);

    for (int i = 1; i < size; i++) {
        if (s[i - 1].getTot() == s[i].getTot()) {
            s[i].setRank(s[i - 1].getRank());
        } else {
            s[i].setRank(i + 1);
        }
    }
}
