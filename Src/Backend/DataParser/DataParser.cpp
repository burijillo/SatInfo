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
            if (!it.value().at("COUNTRY").is_null()) {
                std::cout << it.value().at("COUNTRY") << std::endl;
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