#ifndef RABBIT_HPP
#define RABBIT_HPP
#include "Animal.hpp"

class Rabbit : public Animal {
public:
    Rabbit(int c, int r);
    void update(Game& game) override;
    char getDisplay() const override { return 'R'; }
};

#endif
