#include "Student.hpp"
#include <cstdlib>

Student::Student(int k) : id(k) {
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
