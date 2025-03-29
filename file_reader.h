#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>

class FileReader {
public:
    static bool readConfiguration(const std::string& configFile, std::string& regionFile, int& maxSteps, int& refreshRate);
    static bool readRegionFile(const std::string& regionFile, std::vector<std::vector<char>>& regionLayout);
};

#endif