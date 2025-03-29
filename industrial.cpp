#include "industrial.h"
#include <iostream>

void Industrial::simulateGrowth() {
    if (population < 100) { // Limit growth to a maximum population
        population++;
        std::cout << "Industrial zone at (" << x << ", " << y << ") grew to population " << population << ".\n";
    }
}

void Industrial::updatePollution() {
    pollutionLevel = population * 2; // Example: Pollution scales with population
}
