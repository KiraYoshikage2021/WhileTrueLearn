#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Gui.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <Tigers> <Wolves> <Rabbits>" << endl;
        return 1;
    }

    int nTigers = atoi(argv[1]);
    int nWolves = atoi(argv[2]);
    int nRabbits = atoi(argv[3]);

    srand(time(NULL));

    Game game(nTigers, nWolves, nRabbits);
    Gui gui;

    char input = ' ';
    while (input != 'q') {
        gui.draw(game);
        
        input = cin.get(); 
        
        if (input == 'a') {
            game.addRandomPredator();
        } else if (input == 'd') {
            game.addRandomRabbit();
        }
        
        if (input != 'q') {
            game.update();
        }
    }

    return 0;
}
