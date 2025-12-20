#include "Student.hpp"
#include <cstdlib>

Student::Student(int k) : id(k) {
    // Random p between 0.1 and 0.99
    // rand() % 90 gives 0-89. +10 gives 10-99. /100.0 gives 0.10 - 0.99.
    double p = (rand() % 90 + 10) / 100.0;
    decision = new Decision(p);
}

Student::~Student() {
    delete decision;
}

int Student::MakeDecision(int weather) {
    return decision->MakeDecision(weather);
}

int Student::GetID() const {
    return id;
}
