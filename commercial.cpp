#include "commercial.h"
#include <cstdlib> // Include for rand()

void Commercial::simulateGrowth() {
    if (population < 15) {
        int growthBoost = rand() % 3; // Use global rand()
        population += growthBoost;
        if (population > 15) {
            population = 15;
        }
    }
}

void Commercial::updatePollution() {
    pollutionLevel = population / 10;
}

char Commercial::getZoneType() const {
    return 'C';
}