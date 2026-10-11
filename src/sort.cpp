#include <utility>
#include <vector>

#include "../include/sort.h"
#include "../include/student.hpp"

void bubble_sort(std::vector<Student> &students) {
    int n = students.size();
    bool swapped = false;

    for (int j = 0; j < n - 1; j++) {
        swapped = false;

        for (int k = 0; k < n - j - 1; k++) {
            // high to low
            if (students[k].getTot() < students[k + 1].getTot()) {
                // Student tmp = students[k];
                // students[k] = students[k + 1];
                // students[k + 1] = tmp;

                std::swap(students[k], students[k + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}
