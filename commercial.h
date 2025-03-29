#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "zone.h"

class Commercial : public Zone {
public:
    Commercial(int x, int y) : Zone(x, y) {}

    void simulateGrowth() override;
    void updatePollution() override;
    char getZoneType() const override; // Provide implementation
};

#endif
