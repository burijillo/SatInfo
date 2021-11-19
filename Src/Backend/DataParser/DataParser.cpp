#include "DataParser.h"
#include <filesystem>

DataParser::DataParser()
{
    Logger logger = Logger::GetLogger();
    // Check cookis directory exists
    std::string path = std::filesystem::current_path().string().append("/../../cookies/");
    if (std::filesystem::is_directory(path)){
        // Iterate through the filenames vector to check which files exists
        for (std::string item:dataFileNameVec){
            std::string dataFileName = path + item;
            if (checkIfDataFileExists(dataFileName)){
                existingDataFileNames.push_back(dataFileName);
                std::string logMsg = "Add " + item + " to dataFile set";
                logger.CreateMessage(logMsg);
            }
        }
    } else {
        logger.CreateMessage(path + " doesnt exist!");
    }
}

bool DataParser::checkIfDataFileExists(std::string fileName)
{
    bool result = false;

    if (std::filesystem::exists(fileName)){
        result = true;
    }

    return result;
}