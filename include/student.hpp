#pragma once

#include <string>

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
    Student() {}

    Student(int num, std::string name, int kor, int eng, int math) {
        this->num = num;
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->math = math;

        setTot(kor, eng, math);
    }

    void setNum(int num) { this->num = num; }
    int getNum() { return num; }

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }

    void setKor(int kor) { this->kor = kor; }
    int getKor() { return kor; }

    void setEng(int eng) { this->eng = eng; }
    int getEng() { return eng; }

    void setMath(int math) { this->math = math; }
    int getMath() { return math; }

    void setTot(int kor, int eng, int math) {
        this->tot = kor + eng + math;
        setAvg(tot);
    }
    int getTot() { return tot; }

    void setAvg(int tot) {
        this->avg =
            std::round((static_cast<float>(tot) / 3.0f) * 100.0f) / 100.0f;

        setGrade(avg);
    }
    float getAvg() { return avg; }

    void setGrade(float avg) {
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
    char getGrade() { return grade; }

    void setRank(int rank) { this->rank = rank; }
    int getRank() { return rank; }
};
