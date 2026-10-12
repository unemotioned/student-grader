#pragma once

#include <cmath>
#include <string>
#include <utility>

class Student {
  private:
    int num;
    std::string name;
    int kor;
    int eng;
    int math;
    int tot;
    float avg;
    char grade;
    int rank;

  public:
    Student() = default;

    Student(int num, std::string name, int kor, int eng, int math) {
        this->num = num;
        this->name = std::move(name);
        this->kor = kor;
        this->eng = eng;
        this->math = math;

        set_tot(kor, eng, math);
    }

    void set_num(int num) { this->num = num; }
    [[nodiscard]] int get_num() const { return num; }

    void set_name(std::string name) { this->name = std::move(name); }
    [[nodiscard]] std::string get_name() const { return name; }

    void set_kor(int kor) { this->kor = kor; }
    [[nodiscard]] int get_kor() const { return kor; }

    void set_eng(int eng) { this->eng = eng; }
    [[nodiscard]] int get_eng() const { return eng; }

    void set_math(int math) { this->math = math; }
    [[nodiscard]] int get_math() const { return math; }

    void set_tot(int kor, int eng, int math) {
        this->tot = kor + eng + math;
        set_avg(tot);
    }
    [[nodiscard]] int get_tot() const { return tot; }

    void set_avg(int tot) {
        this->avg =
            std::round((static_cast<float>(tot) / 3.0f) * 100.0f) / 100.0f;

        set_grade(avg);
    }
    [[nodiscard]] float get_avg() const { return avg; }

    void set_grade(float avg) {
        if (avg >= 90.0) {
            grade = 'A';
        } else if (avg >= 80.0) {
            grade = 'B';
        } else if (avg >= 70.0) {
            grade = 'C';
        } else if (avg >= 60.0) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }
    [[nodiscard]] char get_grade() const { return grade; }

    void set_rank(int rank) { this->rank = rank; }
    [[nodiscard]] int get_rank() const { return rank; }
};
