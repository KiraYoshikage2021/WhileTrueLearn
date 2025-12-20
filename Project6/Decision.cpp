#include "Decision.hpp"
#include <cstdlib>

Decision::Decision(double val) : x(val) {}

int Decision::MakeDecision(int weather) {
    double probPlay = 0.0;
    // Weather mapping logic
    switch (weather) {
        case 1: probPlay = x; break;
        case 2: probPlay = 1.0 - (x / 2.0); break;
        case 3: probPlay = x; break;
        case 4: probPlay = 1.0 - (x / 2.0); break;
        case 5: probPlay = 1.0; break;
        default: probPlay = 0.0; break;
    }
    double r = (double)rand() / RAND_MAX;
    return (r < probPlay) ? 0 : 1;
}
