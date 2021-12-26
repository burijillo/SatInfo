#include "curl_manager.h"
#include "../Log/Logger.h"

/**
 * @brief Construct a new curl manager::curl manager object
 * 
 */
curl_manager::curl_manager(){

    current_path = std::filesystem::current_path();
}

/**
 * @brief Destroy the curl manager::curl manager object
 * 
 */
curl_manager::~curl_manager() {
    if (curl != nullptr) {
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
}

/**
 * @brief Authentication on space track server
 * 
 * @param cookies_path File where session cookies are going to be stored
 * @param config_path File where user and password are stored
 * @return true if authentication is done, false otherwise 
 */
bool curl_manager::curl_auth(const std::string cookies_path, const std::string config_path) {
    bool res = false;
    CURLcode ret;
    Logger& logger = Logger::GetLogger();

    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, cookies_path.c_str());
    if (check_config_file(config_path)) {
        std::stringstream config_data_ss;
        config_data_ss << "identity=" << space_track_user << "&password=" << space_track_pwd;
        std::string config_data = config_data_ss.str();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, config_data.c_str());
        struct curl_slist *cookies = nullptr;
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.space-track.org/ajaxauth/login");
        ret = curl_easy_perform(curl);
        if (ret == CURLE_OK){
            ret = curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &cookies);
            if(ret == CURLE_OK && cookies) {
                logger.CreateMessage("COOKIES", IObserver::LOG_TYPE::LOG);
                struct curl_slist *each = cookies;
                while(each) {
                    logger.CreateMessage(each->data, IObserver::LOG_TYPE::LOG);
                    each = each->next;
                }
                curl_slist_free_all(cookies);
            }
        }
        res = true;
    } else {
        res = false;
    }

    curl_easy_reset(curl);
    
    return res;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void curl_manager::download_data(const download_type _download_type) {
    CURLcode ret;
    // Check which download type
    std::string download_url = download_manager(_download_type);

    curl = curl_easy_init();
    if (curl != nullptr) {
        std::string cookies_path = current_path + ("/../../cookies/cookies_space_track.txt");
        std::string config_path = current_path + ("/../../cookies/config.txt");
        std::string json_out_path = current_path + ("/../../Down_Data.json");

        curl_auth(cookies_path, config_path);

        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_COOKIEJAR, cookies_path.c_str());
        //curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, (curl_off_t)100000);
        // TODO REVISIT SO SEARCH IS CONFIGURABLE
        curl_easy_setopt(curl, CURLOPT_URL,download_url.c_str());
        FILE* fp;
        fp = fopen(json_out_path.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        ret = curl_easy_perform(curl);
        log_download_data();
        fclose(fp);

        curl_easy_cleanup(curl);
        curl = nullptr;
    }
}

std::string curl_manager::download_manager(const download_type _download_type) {
    std::string res = "";

    switch (_download_type) {
        case download_type::CURRENT_DATA:
        res = "https://www.space-track.org/basicspacedata/query/class/boxscore/format/json";
        //res = "https://www.space-track.org/basicspacedata/query/class/satcat/format/json";
        //res = "https://www.space-track.org/basicspacedata/query/class/satcat/format/csv";

        break;
    }

    return res;
}

/**
 * @brief Check if configuration file for space track user and password web exists
 * 
 * This configuration file is txt for the moment. TODO
 * 
 * @param config_path path where configuration file is located
 * @return true in case configuration file was loaded correctly, false otherwise 
 */
bool curl_manager::check_config_file(const std::string config_path) {
    bool res = false;

    // Check if config file exists
    std::ifstream config_file (config_path);
    if (config_file.is_open()){
        std::string line;
        while (std::getline(config_file, line)) {
            // Check key
            std::string key = line.substr(0, line.find("="));

            if (key == "user") {
                space_track_user = line.substr(line.find("=") + 1, (line.length() - line.find("=")));
            } else if (key == "pwd") {
                space_track_pwd = line.substr(line.find("=") + 1, (line.length() - line.find("=")));
            } else {
                // TODO REVISIT WHEN LOG EXISTS
                std::cout << "Bad config data\n";
                res = false;
            }
        }
        res = true;
        config_file.close();    
    } else {
        // TODO REVISIT WHEN LOG EXISTS
        std::cout << config_path << " doesnt exist\n";
        res = false;
    }

    return res;
}

/**
 * @brief Log download data
 * 
 */
void curl_manager::log_download_data() {
    CURLcode ret;
    Logger& logger = Logger::GetLogger();
    std::string log;

    // Get download size
    curl_off_t down_data;
    ret = curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD_T, &down_data);
    if (ret == CURLE_OK) {
        log = "Downloaded: " + std::to_string(down_data) + " bytes";
        logger.CreateMessage(log, IObserver::LOG_TYPE::LOG);
    }
    curl_off_t speed_data;
    ret = curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD_T, &speed_data);
    if (ret == CURLE_OK) {
        log = "Download speed: " + std::to_string(speed_data) + " bytes/sec";
        logger.CreateMessage(log, IObserver::LOG_TYPE::LOG);
    }
}