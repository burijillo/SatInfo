#include "DataParser.h"
#include <filesystem>
#include <fstream>

DataParser::DataParser()
{
    Logger logger = Logger::GetLogger();
    // Check cookis directory exists
    dataPath = std::filesystem::current_path().string().append("/../../cookies/");
    if (std::filesystem::is_directory(dataPath)){
        // Iterate through the filenames vector to check which files exists
        for (std::string item:dataFileNameVec){
            std::string dataFileName = dataPath + item;
            if (checkIfDataFileExists(dataFileName)){
                existingDataFileNames.push_back(dataFileName);
                std::string logMsg = "Add " + item + " to dataFile set";
                logger.CreateMessage(logMsg, IObserver::LOG_TYPE::PARSER);
            }
        }
        isCookiesADirectory = true;
    } else {
        logger.CreateMessage(dataPath + " doesnt exist!", IObserver::LOG_TYPE::PARSER);
        isCookiesADirectory = false;
    }
}

bool DataParser::parseBoxCat()
{
    bool result = false;

    // Check if BoxCat exists
    std::string boxCatPath = dataPath + "BoxScore.json";
    if (std::find(existingDataFileNames.begin(), existingDataFileNames.end(), boxCatPath) != existingDataFileNames.end()) {
        std::ifstream fs(boxCatPath, std::ifstream::in);
        nlohmann::json jParser;
        jParser = nlohmann::json::parse(fs);

        for (auto it = jParser.begin(); it != jParser.end(); ++it) {
            if (!it.value().at(boxCatProp[0]).is_null()) {
                std::string country = it.value().at(boxCatProp[0]);
                boxCat.setnNewItem(country);
            }
        }

        Logger logger = Logger::GetLogger();
        std::string boxCatSize = "";
        boxCatSize = "Number of countries/orgs: " + std::to_string(boxCat.getSize());
        logger.CreateMessage(boxCatSize, IObserver::LOG_TYPE::PARSER);

        /*std::vector<BoxUnit> boxCatVec = boxCat.getBoxCatVec();
        for (auto item:boxCatVec){
            std::string test = item.country;
            logger.CreateMessage("COUNTRY ID " + std::to_string(item.id) + " : " + test, IObserver::LOG_TYPE::PARSER);
        }*/
        for (int i = 0; i < boxCat.getSize() + 2; i++){
            BoxUnit boxUnit = boxCat.getBoxUnit(i);
            if (boxUnit.isValid) {
                logger.CreateMessage("COUNTRY ID " + std::to_string(boxUnit.id) + " : " + boxUnit.country, IObserver::LOG_TYPE::PARSER);
            } else {
                logger.CreateMessage("ERROR MASEMO", IObserver::LOG_TYPE::SYS_ERR);
            }
        }


    } else {
        result = false;
    }

    return result;
}

bool DataParser::checkIfDataFileExists(std::string fileName)
{
    bool result = false;

    if (std::filesystem::exists(fileName)){
        result = true;
    }

    return result;
}