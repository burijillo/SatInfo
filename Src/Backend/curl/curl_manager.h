#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <curl/curl.h>
#include <json.hpp>
#include <thread>

class curl_manager
{
    public:

        enum class download_type {
            CURRENT_DATA = 0,
        };

        curl_manager();
        ~curl_manager();

        void download_data(const download_type _download_type);
    
    private:
        CURL *curl;

        bool curl_auth(const std::string cookies_path, const std::string config_path);
        bool check_config_file(const std::string config_path);
        std::string download_manager(const download_type _download_type);
        void log_download_data();

        std::string current_path;

        std::string space_track_user;
        std::string space_track_pwd;
};