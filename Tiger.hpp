#ifndef TIGER_HPP
#define TIGER_HPP
#include "Predator.hpp"

class Tiger : public Predator {
public:
    Tiger(int c, int r);
    void update(Game& game) override;
    char getDisplay() const override { return 'T'; }
};

#endif
