#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "zone.h"

class Industrial : public Zone {
public:
    Industrial(int x, int y) : Zone(x, y) {
        population = 20; // Initialize with a default population
    }

    void simulateGrowth() override;
    void updatePollution() override;

    char getZoneType() const override {
        return 'I'; // Identify as industrial zone
    }
};

#endif // INDUSTRIAL_H
