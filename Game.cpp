#include "Game.hpp"
#include "Rabbit.hpp"
#include "Wolf.hpp"
#include "Tiger.hpp"
#include <cstdlib>
#include <cmath>
#include <algorithm>

Game::Game(int t, int w, int r) : width(80), height(25), day(0) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            grass.push_back(new Grass(i, j));
        }
    }

    for (int i = 0; i < t; i++) animals.push_back(new Tiger(rand()%80, rand()%25));
    for (int i = 0; i < w; i++) animals.push_back(new Wolf(rand()%80, rand()%25));
    for (int i = 0; i < r; i++) animals.push_back(new Rabbit(rand()%80, rand()%25));
}

Game::~Game() {
    for (auto a : animals) delete a;
    for (auto g : grass) delete g;
}

Grass* Game::getGrass(int c, int r) {
    if (c < 0 || c >= width || r < 0 || r >= height) return nullptr;
    return grass[r * width + c];
}

Animal* Game::findClosestPrey(int c, int r, int range, std::string type) {
    for (auto a : animals) {
        if (!a->isDead() && a->getType() == type) {
            int dx = abs(a->getX() - c);
            int dy = abs(a->getY() - r);
            if (dx <= range && dy <= range) {
                return a;
            }
        }
    }
    return nullptr;
}

void Game::update() {
    day++;
    
    for (auto a : animals) {
        a->update(*this);
    }

    auto it = std::remove_if(animals.begin(), animals.end(), [](Animal* a) {
        if (a->isDead()) {
            delete a;
            return true;
        }
        return false;
    });
    animals.erase(it, animals.end());

    for (auto g : grass) {
        g->tick();
    }
}

void Game::addRandomPredator() {
    if (rand() % 2 == 0)
        animals.push_back(new Wolf(rand()%80, rand()%25));
    else
        animals.push_back(new Tiger(rand()%80, rand()%25));
}

void Game::addRandomRabbit() {
    animals.push_back(new Rabbit(rand()%80, rand()%25));
}
