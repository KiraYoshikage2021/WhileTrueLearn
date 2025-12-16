#include "Wolf.hpp"
#include "Game.hpp"

Wolf::Wolf(int c, int r) : Predator(c, r, "Wolf") {}

void Wolf::update(Game& game) {
    if (dead) return;

    Animal* prey = game.findClosestPrey(x, y, 2, "Rabbit");

    if (prey) {
        x = prey->getX();
        y = prey->getY();
        prey->kill();
        daysWithoutFood = 0;
    } else {
        moveRandomly(2);
        daysWithoutFood++;
    }

    if (daysWithoutFood >= 3) {
        dead = true;
    }
}
