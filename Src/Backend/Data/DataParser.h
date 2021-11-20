#pragma once
#include "../json.hpp"
#include <string>
#include <vector>
#include "../Log/Logger.h"
#include "DataSets/BoxCat.h"

class DataParser
{
public:
    DataParser();
    bool parseBoxCat();
private:
    // Data filenames
    std::vector<std::string> dataFileNameVec {
        "BoxScore.json",
        "SatCat.json"
    };
    bool isCookiesADirectory = false;
    std::vector<std::string> existingDataFileNames;
    std::string dataPath;

    std::vector<BoxCat> boxCatVec;

    bool checkIfDataFileExists(std::string fileName);
};