#pragma once
#include "../Log/Logger.h"
#include "../json.hpp"
#include "DataSets/BoxCat.h"
#include <string>
#include <vector>

class DataParser {
public:
    DataParser();

    bool getBoxCatLoaded() { return isBoxCatLoaded; }
    bool parseBoxCat();
    std::map<std::string, int> getBoxCatNameMap() { return boxCatNameMap; }

private:
    // Data filenames
    std::vector<std::string> dataFileNameVec {"BoxScore.json", "SatCat.json"};
    bool isCookiesADirectory = false;
    std::vector<std::string> existingDataFileNames;
    std::string dataPath;

    bool isBoxCatLoaded = false;
    BoxCat boxCat;
    std::map<std::string, int> boxCatNameMap;

    bool checkIfDataFileExists(std::string fileName);
};