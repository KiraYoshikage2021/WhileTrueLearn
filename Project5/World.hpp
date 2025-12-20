#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "Group.hpp"
#include "Weather.hpp"

class World {
private:
    std::vector<Group*> groups;
    Weather* w;
    int nextStudentID; // Track IDs to ensure uniqueness across groups

public:
    World(size_t c); // c is number of groups
    ~World();
    void DoSimulation();
};

#endif
