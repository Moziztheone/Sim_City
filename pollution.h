#ifndef POLLUTION_H
#define POLLUTION_H

#include <vector>

class Pollution {
public:
    static void updatePollution(std::vector<std::vector<int>>& pollutionMap, const std::vector<std::vector<int>>& industrialZones);
    static int calculateTotalPollution(const std::vector<std::vector<int>>& pollutionMap);
};

#endif
