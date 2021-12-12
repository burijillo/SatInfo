#include "DataParser.h"
#include <filesystem>
#include <fstream>

DataParser::DataParser() {
    Logger logger = Logger::GetLogger();
    // Check cookis directory exists
    dataPath = std::filesystem::current_path().string().append("/../../cookies/");
    if(std::filesystem::is_directory(dataPath)) {
        // Iterate through the filenames vector to check which files exists
        for(std::string item : dataFileNameVec) {
            std::string dataFileName = dataPath + item;
            if(checkIfDataFileExists(dataFileName)) {
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

bool DataParser::parseBoxCat() {
    bool result = false;

    // Check if boxCat was already loaded
    if(!isBoxCatLoaded) {
        isBoxCatLoaded = true;

        // Check if BoxCat exists
        std::string boxCatPath = dataPath + "BoxScore.json";
        if(std::find(existingDataFileNames.begin(), existingDataFileNames.end(), boxCatPath) !=
            existingDataFileNames.end()) {
            std::ifstream fs(boxCatPath, std::ifstream::in);
            nlohmann::json jParser;
            jParser = nlohmann::json::parse(fs);

            for(const auto &item : jParser.items()) {
                std::string country;
                std::string spadoc_cd;
                std::string orbital_tba;
                std::string orbital_payload_count;
                std::string orbital_rocket_count;
                std::string orbital_debris_count;
                std::string orbital_total_count;
                std::string decayed_payload_count;
                std::string decayed_rocket_count;
                std::string decayed_debris_count;
                std::string decayed_total_count;
                std::string country_total;

                country               = item.value()[boxCatProp[0]].get<std::string>();
                spadoc_cd             = item.value()[boxCatProp[1]].get<std::string>();
                orbital_tba           = item.value()[boxCatProp[2]].get<std::string>();
                orbital_payload_count = item.value()[boxCatProp[3]].get<std::string>();
                orbital_rocket_count  = item.value()[boxCatProp[4]].get<std::string>();
                orbital_debris_count  = item.value()[boxCatProp[5]].get<std::string>();
                orbital_total_count   = item.value()[boxCatProp[6]].get<std::string>();
                decayed_payload_count = item.value()[boxCatProp[7]].get<std::string>();
                decayed_rocket_count  = item.value()[boxCatProp[8]].get<std::string>();
                decayed_debris_count  = item.value()[boxCatProp[9]].get<std::string>();
                decayed_total_count   = item.value()[boxCatProp[10]].get<std::string>();
                country_total         = item.value()[boxCatProp[11]].get<std::string>();

                boxCat.setnNewItem(country, spadoc_cd, orbital_tba, orbital_payload_count,
                    orbital_rocket_count, orbital_debris_count, orbital_total_count,
                    decayed_payload_count, decayed_rocket_count, decayed_debris_count,
                    decayed_total_count, country_total);

                boxCatNameMap.insert(
                    std::pair<std::string, int>(country, std::stoi(country_total)));
            }

            Logger logger          = Logger::GetLogger();
            std::string boxCatSize = "";
            boxCatSize = "Number of countries/orgs: " + std::to_string(boxCat.getSize());
            logger.CreateMessage(boxCatSize, IObserver::LOG_TYPE::PARSER);

            /*std::vector<BoxUnit> boxCatVec = boxCat.getBoxCatVec();
            for (auto item:boxCatVec){
                std::string test = item.country;
                logger.CreateMessage("COUNTRY ID " + std::to_string(item.id) + " : "
            + test, IObserver::LOG_TYPE::PARSER);
            }*/
            for(int i = 0; i < boxCat.getSize(); i++) {
                BoxUnit boxUnit = boxCat.getBoxUnit(i);
                if(boxUnit.isValid) {
                    /*logger.CreateMessage("COUNTRY " + std::to_string(boxUnit.id) + " : " +
                                             boxUnit.country + " - " + boxUnit.spadoc_cd,
                        IObserver::LOG_TYPE::PARSER);*/

                } else {
                    logger.CreateMessage("ERROR MASEMO", IObserver::LOG_TYPE::SYS_ERR);
                }
            }

            dataParserType = DataParserType::BOXCAT;

        } else {
            result = false;
        }
    }

    return result;
}

BoxUnit DataParser::getBoxUnit(std::string name) {
    BoxUnit result;
    result.isValid = false;

    if(isBoxCatLoaded) {
        result = boxCat.getBoxUnit(name);
    }

    return result;
}

bool DataParser::checkIfDataFileExists(std::string fileName) {
    bool result = false;

    if(std::filesystem::exists(fileName)) {
        result = true;
    }

    return result;
}