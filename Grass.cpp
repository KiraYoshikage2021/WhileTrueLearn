#include "Grass.hpp"

Grass::Grass(int c, int r) : Item(c, r), growth(0) {}

void Grass::tick() {
    if (growth < 3) {
        growth++;
    }
}

void Grass::eat() {
    growth = 0;
}

bool Grass::isFull() const {
    return growth >= 3;
}

char Grass::getDisplay() const {
    if (growth == 0) return ' ';
    if (growth == 1) return '.';
    if (growth == 2) return ':';
    return '*'; 
}
