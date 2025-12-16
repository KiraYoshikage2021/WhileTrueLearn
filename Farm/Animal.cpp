#include "Animal.hpp"
#include <cstdlib>

Animal::Animal(int c, int r, std::string t) 
    : Item(c, r), daysWithoutFood(0), dead(false), type(t) {}

void Animal::moveRandomly(int range) {
    int dx = (rand() % (2 * range + 1)) - range;
    int dy = (rand() % (2 * range + 1)) - range;
    
    x += dx;
    y += dy;
    
    if (x < 0) x = 0;
    if (x >= 80) x = 79;
    if (y < 0) y = 0;
    if (y >= 25) y = 24;
}
