#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool FileReader::readConfiguration(const std::string& configFile, std::string& regionFile, int& maxSteps, int& refreshRate) {
    // Debugging output to check the file path
    std::cout << "Attempting to open configuration file: " << configFile << std::endl;

    // Attempt to open the file
    std::ifstream file(configFile);
    if (!file.is_open()) {
        // Print the file path and error message if the file cannot be opened
        std::cerr << "Error: Could not open configuration file: " << configFile << std::endl;
        return false;
    }

    // Read the region file name
    std::getline(file, regionFile);
    // Read the maximum steps
    file >> maxSteps;
    // Read the refresh rate
    file >> refreshRate;

    // Additional debugging output to confirm the configuration was read
    std::cout << "Configuration read successfully:" << std::endl;
    std::cout << "Region file: " << regionFile << std::endl;
    std::cout << "Max steps: " << maxSteps << std::endl;
    std::cout << "Refresh rate: " << refreshRate << std::endl;

    file.close();
    return true;
}

bool FileReader::readRegionFile(const std::string& regionFile, std::vector<std::vector<char>>& regionLayout) {
    std::cout << "Attempting to open region file: " << regionFile << std::endl;

    std::ifstream file(regionFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open region file: " << regionFile << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char cell : line) {
            if (!isspace(cell)) {
                row.push_back(cell);
            }
        }
        regionLayout.push_back(row);
    }

    if (regionLayout.empty()) {
        std::cerr << "Error: Region file is empty or improperly formatted." << std::endl;
        return false;
    }

    file.close();
    return true;
}
