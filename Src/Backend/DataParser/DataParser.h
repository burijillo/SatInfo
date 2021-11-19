#pragma once
#include "../json.hpp"
#include <string>
#include <vector>
#include "../Log/Logger.h"

class DataParser
{
public:
    DataParser();
private:
    // Data filenames
    std::vector<std::string> dataFileNameVec {
        "BoxScore.json",
        "SatCat.json"
    };

    std::vector<std::string> existingDataFileNames;

    bool checkIfDataFileExists(std::string fileName);
};