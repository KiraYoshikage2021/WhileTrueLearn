#ifndef GRASS_HPP
#define GRASS_HPP
#include "Item.hpp"

class Grass : public Item {
private:
    int growth; // 0, 1, 2, 3 (3 represents full)
public:
    Grass(int c, int r);
    void tick(); // Daily update
    void eat();  // Called when eaten
    bool isFull() const;
    char getDisplay() const;
};

#endif
