#include "residential.h"
#include <cstdlib> // Include for rand()

void Residential::simulateGrowth() {
    if (population < 10) {
        int growthChance = rand() % 100; // Use global rand()
        if (population == 0 && growthChance < 50) {
            population++;
        } else if (population == 1 && growthChance < 70) {
            population++;
        } else if (population >= 2 && growthChance < 40) {
            population++;
        }
    }
}

void Residential::updatePollution() {
    pollutionLevel = population / 5;
}

char Residential::getZoneType() const {
    return 'R';
}
