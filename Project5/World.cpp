#include "World.hpp"
#include <iostream>
#include <cstdlib>

World::World(size_t c) {
    w = new Weather();
    nextStudentID = 0;
    
    // "each group has 30 std"
    for (size_t i = 0; i < c; i++) {
        groups.push_back(new Group(nextStudentID, 30));
        nextStudentID += 30; 
    }
}

World::~World() {
    delete w;
    for (Group* g : groups) {
        delete g;
    }
    groups.clear();
}

void World::DoSimulation() {
    // For each day of a month (30 days)
    for (int day = 1; day <= 30; day++) {
        std::cout << "--- Day " << day << " ---" << std::endl;
        
        // 1. 40% chance to randomly pick and split a group
        if (!groups.empty() && (rand() % 100 < 40)) {
            int idx = rand() % groups.size();
            Group* newGroup = groups[idx]->Split();
            if (newGroup != nullptr) {
                groups.push_back(newGroup);
                std::cout << "[Event] Group " << idx << " split! Total groups: " << groups.size() << std::endl;
            }
        }

        // 2. Update weather
        w->UpdateWeather();
        int currentW = w->GetWeather();
        std::cout << "Weather: " << currentW << std::endl;

        // 3. Call each group to make decision and report
        for (size_t i = 0; i < groups.size(); i++) {
            std::cout << "Group " << i << ":" << std::endl;
            groups[i]->GroupDecision(currentW);
            groups[i]->Report();
        }
        std::cout << std::endl;
    }
}
