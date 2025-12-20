#ifndef WORLD_HPP
#define WORLD_HPP

#include "Group.hpp"
#include "Weather.hpp"

class World {
private:
    // Manual dynamic array of Group pointers
    Group** groups;
    size_t groupCount;
    size_t groupCapacity;

    Weather* w;
    int nextStudentID;

    // Helper to manage array
    void AddGroup(Group* g);
    void RemoveGroupAt(size_t index);

public:
    World(size_t c);
    ~World();
    void DoSimulation();
};

#endif
