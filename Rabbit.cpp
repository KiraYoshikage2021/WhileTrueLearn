#include "Rabbit.hpp"
#include "Game.hpp" 

Rabbit::Rabbit(int c, int r) : Animal(c, r, "Rabbit") {}

void Rabbit::update(Game& game) {
    if (dead) return;

    moveRandomly(1);

    Grass* g = game.getGrass(x, y);
    if (g && g->isFull()) {
        g->eat();
        daysWithoutFood = 0;
    } else {
        daysWithoutFood++;
    }

    if (daysWithoutFood >= 2) {
        dead = true;
    }
}
