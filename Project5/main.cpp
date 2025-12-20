#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.hpp"

int main() {
    srand(time(NULL));

    // Example: Create world with 5 groups
    std::cout << "Initializing World with 5 groups..." << std::endl;
    World world(5);

    world.DoSimulation();

    return 0;
}
