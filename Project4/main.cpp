#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Experiment.hpp"

using namespace std;

int main() {
    
    srand(time(NULL));
    DoExperiment(1000);

    return 0;
}
