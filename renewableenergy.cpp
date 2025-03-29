#include "renewableenergy.h"
#include <iostream>
#include <algorithm>

RenewableEnergy::RenewableEnergy(int x, int y, int power, int cost, int reduction, int range, RenewableType type)
    : Zone(x, y), powerOutput(power), maintenanceCost(cost), pollutionReduction(reduction), range(range), type(type) {}

void RenewableEnergy::simulateGrowth() {
    powerOutput += 4;
}

void RenewableEnergy::updatePollution() {
    pollutionLevel = std::max(0, pollutionLevel - pollutionReduction);
}

char RenewableEnergy::getZoneType() const {
    switch (type) {
        case SOLAR: return 'S';
        case WIND: return 'W';
        case NUCLEAR: return 'N';
        default: return 'E';
    }
}

void RenewableEnergy::checkConnectivity(std::vector<std::vector<Zone*>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int dx = -range; dx <= range; ++dx) {
        for (int dy = -range; dy <= range; ++dy) {
            int newX = x + dx;
            int newY = y + dy;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                Zone* zone = grid[newX][newY];
                if (zone) {
                    std::cout << "Renewable zone at (" << x << ", " << y << ") "
                              << "is connected to zone at (" << newX << ", " << newY << ")\n";
                }
            }
        }
    }
}

int RenewableEnergy::getPowerOutput() const {
    return powerOutput;
}

int RenewableEnergy::getMaintenanceCost() const {
    return maintenanceCost;
}

int RenewableEnergy::getPollutionReduction() const {
    return pollutionReduction;
}

int RenewableEnergy::getRange() const {
    return range;
}
