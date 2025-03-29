#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <algorithm>

class Zone {
protected:
    int x, y;
    int population;
    int pollutionLevel;
    bool energyReceived;

public:
    Zone(int x, int y) : x(x), y(y), population(0), pollutionLevel(0), energyReceived(false) {}
    virtual ~Zone() {}

    virtual void simulateGrowth() = 0;
    virtual void updatePollution() = 0;
    virtual char getZoneType() const = 0;

    int getPopulation() const { return population; }
    int getPollution() const { return pollutionLevel; }
    bool hasEnergy() const { return energyReceived; }
    void receiveEnergy(int power) { energyReceived = true; }
};

#endif // ZONE_H
