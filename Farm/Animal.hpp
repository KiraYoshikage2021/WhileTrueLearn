#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Item.hpp"
#include <string>

// Forward declaration needed because Animals need to check Game state
class Game; 

class Animal : public Item {
protected:
    int daysWithoutFood;
    bool dead;
    std::string type; // "Rabbit", "Wolf", "Tiger"

public:
    Animal(int c, int r, std::string t);
    virtual ~Animal() {}
    
    virtual void update(Game& game) = 0; // Pure virtual
    virtual char getDisplay() const = 0;
    
    bool isDead() const { return dead; }
    void kill() { dead = true; }
    std::string getType() const { return type; }
    
    void moveRandomly(int range);
};

#endif
