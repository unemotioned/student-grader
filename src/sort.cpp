#include <utility>
#include <vector>

#include "../include/sort.h"
#include "../include/student.hpp"

void bubble_sort(std::vector<Student> &students) {
    const int size = static_cast<int>(students.size());
    bool swapped = false;

    for (int j = 0; j < size - 1; j++) {
        swapped = false;

        for (int k = 0; k < size - j - 1; k++) {
            // high to low
            if (students[k].get_tot() < students[k + 1].get_tot()) {
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
