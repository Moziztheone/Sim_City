#include "pollution.h"
#include <vector>
#include <algorithm>

void Pollution::updatePollution(std::vector<std::vector<int>>& pollutionMap, const std::vector<std::vector<int>>& industrialZones) {
    int height = pollutionMap.size();
    int width = pollutionMap[0].size();

    // Spread pollution from industrial zones
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (industrialZones[i][j] > 0) {
                int pollutionLevel = industrialZones[i][j];
                pollutionMap[i][j] += pollutionLevel;

                // Spread pollution to adjacent cells
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < height && nj >= 0 && nj < width && (di != 0 || dj != 0)) {
                            pollutionMap[ni][nj] += std::max(0, pollutionLevel - 1);
                        }
                    }
                }
            }
        }
    }
}

int Pollution::calculateTotalPollution(const std::vector<std::vector<int>>& pollutionMap) {
    int totalPollution = 0;
    for (const auto& row : pollutionMap) {
        for (int pollution : row) {
            totalPollution += pollution;
        }
    }
    return totalPollution;
}