#include "Decision.hpp"
#include <cstdlib>

Decision::Decision(double val) : x(val) {}

int Decision::MakeDecision(int weather) {
    // 0 = Play, 1 = Not Play
    // Calculate probability of PLAY based on the tree image
    double probPlay = 0.0;

    // Weather mapping:
    // 1: sunny and humid (>70)
    // 2: sunny and not humid (<=70)
    // 3: raining and windy (True)
    // 4: raining and not windy (False)
    // 5: overcast

    switch (weather) {
        case 1: // Sunny + Humid (>70) -> Tree: Play x
            probPlay = x;
            break;
        case 2: // Sunny + Not Humid (<=70) -> Tree: Play 1 - x/2
            probPlay = 1.0 - (x / 2.0);
            break;
        case 3: // Rain + Windy (True) -> Tree: Play x
            probPlay = x;
            break;
        case 4: // Rain + Not Windy (False) -> Tree: Play 1 - x/2
            probPlay = 1.0 - (x / 2.0);
            break;
        case 5: // Overcast -> Tree: Play 1
            probPlay = 1.0;
            break;
        default:
            probPlay = 0.0;
            break;
    }

    double r = (double)rand() / RAND_MAX;
    if (r < probPlay) {
        return 0; // Play
    } else {
        return 1; // Not Play
    }
}
