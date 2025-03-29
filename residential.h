#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "zone.h"

class Residential : public Zone {
public:
    Residential(int x, int y) : Zone(x, y) {}

    void simulateGrowth() override;
    void updatePollution() override;
    char getZoneType() const override; // Provide implementation
};

#endif
