#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <curl/curl.h>

class curl_manager
{
    public:
        curl_manager();
    
    private:
        CURL *curl;

        bool curl_auth(const std::string cookies_path, const std::string config_path);
        bool check_config_file(const std::string config_path);
        void log_download_data();

        std::string current_path;

        std::string space_track_user;
        std::string space_track_pwd;
};