#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Animal.hpp"
#include "Grass.hpp"

class Game {
private:
    std::vector<Animal*> animals;
    std::vector<Grass*> grass;
    int width;
    int height;
    int day;

public:
    Game(int tigers, int wolves, int rabbits);
    ~Game();

    void update();
    void addRandomPredator();
    void addRandomRabbit();
    
    Grass* getGrass(int c, int r);
    Animal* findClosestPrey(int c, int r, int range, std::string type);
    
    const std::vector<Animal*>& getAnimals() const { return animals; }
    const std::vector<Grass*>& getGrassList() const { return grass; }
    int getDay() const { return day; }
};

#endif

