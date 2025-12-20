#ifndef GROUP_HPP
#define GROUP_HPP

#include <iostream>
#include "StudentVector.hpp"

class Group {
private:
    StudentVector students;
    
    // Manual array for decisions log
    int* decisions;     
    size_t decisionCount; 

public:
    Group(int startingID, size_t c);
    // Needed for dynamic allocation management
    Group(const Group& other) = delete; 
    Group& operator=(const Group& other) = delete;

    ~Group();

    void GroupDecision(int weather);
    
    Group& operator+=(Group& other);
    friend std::ostream& operator<<(std::ostream& os, Group& g);

    Group* Split();
    void AddStudent(Student* s);
};

#endif
