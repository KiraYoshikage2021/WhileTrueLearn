#include "Weather.hpp"
#include <cstdlib>

Weather::Weather() {
    current = (rand() % 5) + 1;
}

int Weather::GetWeather() {
    return current;
}

void Weather::UpdateWeather() {
    int r = rand() % 100;
    int next = current;
    // Transfer probability logic
    if (current == 5) {
        if (r < 20) next = 5; else if (r < 40) next = 1; else if (r < 60) next = 2; else if (r < 80) next = 3; else next = 4;
    } else if (current == 1) {
        if (r < 10) next = 1; else if (r < 40) next = 2; else if (r < 80) next = 5; else next = 3;
    } else if (current == 2) {
        if (r < 20) next = 2; else if (r < 50) next = 1; else if (r < 80) next = 5; else if (r < 90) next = 3; else next = 4;
    } else if (current == 3) {
        if (r < 10) next = 3; else if (r < 40) next = 5; else if (r < 60) next = 1; else if (r < 90) next = 4; else next = 2;
    } else if (current == 4) {
        if (r < 20) next = 4; else if (r < 40) next = 5; else if (r < 70) next = 1; else if (r < 90) next = 3; else next = 2;
    }
    current = next;
}
