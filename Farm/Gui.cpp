
#include "Gui.hpp"
#include <iostream>
#include <vector>

void Gui::draw(const Game& game) {
    char screen[25][80];

    for (auto g : game.getGrassList()) {
        screen[g->getY()][g->getX()] = g->getDisplay();
    }

    for (auto a : game.getAnimals()) {
        if (!a->isDead()) {
            screen[a->getY()][a->getX()] = a->getDisplay();
        }
    }

    // Clear console
    std::cout << "\033[2J\033[1;1H"; 
    
    std::cout << "Day: " << game.getDay() << " | Animals: " << game.getAnimals().size() << std::endl;
    std::cout << "Controls: [Enter] Next Day, [a] Add Predator, [d] Add Rabbit, [q] Quit" << std::endl;
    
    for(int i=0; i<82; i++) std::cout << "#";
    std::cout << std::endl;

    for (int j = 0; j < 25; j++) {
        std::cout << "#";
        for (int i = 0; i < 80; i++) {
            std::cout << screen[j][i];
        }
        std::cout << "#" << std::endl;
    }
    
    for(int i=0; i<82; i++) std::cout << "#";
    std::cout << std::endl;
}
