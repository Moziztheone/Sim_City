#ifndef RENEWABLEENERGY_H
#define RENEWABLEENERGY_H

#include "zone.h"
#include <vector>

enum RenewableType { SOLAR, WIND, NUCLEAR };

class RenewableEnergy : public Zone {
private:
    int powerOutput;
    int maintenanceCost;
    int pollutionReduction;
    int range; // Maximum range of connectivity
    RenewableType type;

public:
    RenewableEnergy(int x, int y, int power, int cost, int reduction, int range, RenewableType type);

    void simulateGrowth() override;
    void updatePollution() override;
    char getZoneType() const override;

    void checkConnectivity(std::vector<std::vector<Zone*>>& grid);

    int getPowerOutput() const;
    int getMaintenanceCost() const;
    int getPollutionReduction() const;
    int getRange() const;
};

#endif