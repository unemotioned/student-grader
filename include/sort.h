#pragma once

// Declare interface to allow function call from main.cpp and implement it by
// sort.cpp

#include <vector>

#include "student.hpp"

void bubble_sort(std::vector<Student> &students);
