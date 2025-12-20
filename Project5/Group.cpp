#include "Group.hpp"
#include <iostream>

Group::Group(int startingID, size_t c) {
    for (size_t i = 0; i < c; i++) {
        students.push_back(new Student(startingID + i));
    }
}

Group::Group(std::vector<Student*> movedStudents) {
    students = movedStudents;
}

Group::~Group() {
    for (Student* s : students) {
        delete s;
    }
    students.clear();
}

void Group::GroupDecision(int weather) {
    decisions.clear();
    for (Student* s : students) {
        decisions.push_back(s->MakeDecision(weather));
    }
}

void Group::Report() {
    int playCount = 0;
    int notPlayCount = 0;
    std::vector<int> playIDs;

    for (size_t i = 0; i < decisions.size(); i++) {
        if (decisions[i] == 0) { // 0 is Play
            playCount++;
            playIDs.push_back(students[i]->GetID());
        } else {
            notPlayCount++;
        }
    }

    std::cout << "  Stats: Play=" << playCount << ", NotPlay=" << notPlayCount << std::endl;
    std::cout << "  Play IDs: ";
    for (int id : playIDs) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
}

Group* Group::Split() {
    if (students.size() >= 10) {

        size_t splitIndex = students.size() / 2;
        
        std::vector<Student*> newGroupStudents;
        

        for (size_t i = splitIndex; i < students.size(); i++) {
            newGroupStudents.push_back(students[i]);
        }
        
        students.resize(splitIndex);
        
        return new Group(newGroupStudents);
    }
    return nullptr;
}
