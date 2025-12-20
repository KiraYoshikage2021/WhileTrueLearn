#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>
#include "Student.hpp"

class Group {
private:
    std::vector<Student*> students;
    std::vector<int> decisions;

public:
    // startingID: ID for the first student
    // c: number of students to create
    Group(int startingID, size_t c);
    
    // Constructor for creating a group from existing students (used in Split)
    Group(std::vector<Student*> movedStudents);

    ~Group();

    void GroupDecision(int weather);
    void Report();
    
    // Split the group into two. Returns the new group pointer, or nullptr.
    Group* Split();
};

#endif
