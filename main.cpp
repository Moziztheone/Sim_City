#include "city.h"

int main() {
    int width = 5, height = 5; 
    int maxSteps = 10;
    int refreshRate = 1;

    City myCity(width, height);
    if (!myCity.initialize(maxSteps, refreshRate)) {
        return 1;
    }

    myCity.runSimulation();

    return 0;
}
