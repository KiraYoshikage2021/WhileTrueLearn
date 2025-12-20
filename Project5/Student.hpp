#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Decision.hpp"

class Student {
private:
    int id;
    Decision* decision;

public:
    Student(int k);
    ~Student();
    int MakeDecision(int weather);
    int GetID() const;
};

#endif
