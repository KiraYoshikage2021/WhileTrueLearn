#include "Tiger.hpp"
#include "Game.hpp"
#include <cstdlib>

Tiger::Tiger(int c, int r) : Predator(c, r, "Tiger") {}

void Tiger::update(Game& game) {
    if (dead) return;

    Animal* rabbit = game.findClosestPrey(x, y, 3, "Rabbit");

    if (rabbit) {
        x = rabbit->getX();
        y = rabbit->getY();
        rabbit->kill();
        daysWithoutFood = 0;
    } else {
        Animal* wolf = game.findClosestPrey(x, y, 3, "Wolf");
        bool ateWolf = false;
        
        if (wolf) {
            if (rand() % 3 == 0) {
                x = wolf->getX();
                y = wolf->getY();
                wolf->kill();
                daysWithoutFood = 0;
                ateWolf = true;
            }
        }

        if (!ateWolf) {
            moveRandomly(3);
            daysWithoutFood++;
        }
    }

    if (daysWithoutFood >= 4) {
        dead = true;
    }
}
