#ifndef WOLF_HPP
#define WOLF_HPP
#include "Predator.hpp"

class Wolf : public Predator {
public:
    Wolf(int c, int r);
    void update(Game& game) override;
    char getDisplay() const override { return 'W'; }
};

#endif
