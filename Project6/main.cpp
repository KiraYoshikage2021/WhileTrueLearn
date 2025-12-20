#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.hpp"

int main() {
    srand(time(NULL));
    World world(5);
    world.DoSimulation();
    return 0;
}
