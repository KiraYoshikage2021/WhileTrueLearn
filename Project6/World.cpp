#include "World.hpp"
#include <iostream>
#include <cstdlib>

World::World(size_t c) {
    w = new Weather();
    nextStudentID = 0;
    
    groupCount = 0;
    groupCapacity = 10;
    groups = new Group*[groupCapacity];
    
    for (size_t i = 0; i < c; i++) {
        AddGroup(new Group(nextStudentID, 30));
        nextStudentID += 30; 
    }
}

World::~World() {
    delete w;
    for (size_t i = 0; i < groupCount; i++) {
        delete groups[i];
    }
    delete[] groups;
}

void World::AddGroup(Group* g) {
    if (groupCount == groupCapacity) {
        groupCapacity *= 2;
        Group** temp = new Group*[groupCapacity];
        for (size_t i = 0; i < groupCount; i++) {
            temp[i] = groups[i];
        }
        delete[] groups;
        groups = temp;
    }
    groups[groupCount++] = g;
}

void World::RemoveGroupAt(size_t index) {
    if (index >= groupCount) return;
    
    // Note: This function assumes the object is already deleted or handled outside if needed.
    // But usually, we remove it from list because we want to stop tracking it.
    // In Merge logic, we delete the object BEFORE calling this or inside here?
    // Let's assume caller deletes the object. We just shift the array.
    
    for (size_t i = index; i < groupCount - 1; i++) {
        groups[i] = groups[i + 1];
    }
    groupCount--;
}

void World::DoSimulation() {
    for (int day = 1; day <= 30; day++) {
        std::cout << "--- Day " << day << " ---" << std::endl;
        
        // 1. Split (20%)
        if (groupCount > 0 && (rand() % 100 < 20)) {
            int idx = rand() % groupCount;
            Group* newGroup = groups[idx]->Split();
            if (newGroup != nullptr) {
                AddGroup(newGroup);
                std::cout << "[Event] Group " << idx << " split! Total groups: " << groupCount << std::endl;
            }
        }

        // 2. Merge (20%)
        if (groupCount >= 2 && (rand() % 100 < 20)) {
            int idx1 = rand() % groupCount;
            int idx2 = rand() % groupCount;
            while (idx1 == idx2) {
                idx2 = rand() % groupCount;
            }

            std::cout << "[Event] Merging Group " << idx2 << " into Group " << idx1 << "..." << std::endl;
            
            *groups[idx1] += *groups[idx2];
            
            // Delete the merged group object
            delete groups[idx2];
            
            // Remove pointer from array
            RemoveGroupAt(idx2);
            
            std::cout << "        Merge done. Total groups: " << groupCount << std::endl;
        }

        // 3. Update Weather
        w->UpdateWeather();
        int currentW = w->GetWeather();
        std::cout << "Weather: " << currentW << std::endl;

        // 4. Run Simulation
        for (size_t i = 0; i < groupCount; i++) {
            std::cout << "Group " << i << ":" << std::endl;
            groups[i]->GroupDecision(currentW);
            std::cout << *groups[i]; 
        }
        std::cout << std::endl;
    }
}
