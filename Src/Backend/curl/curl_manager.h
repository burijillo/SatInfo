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
            BOX_CAT = 0,
            SAT_CAT = 1,
        };

        curl_manager();
        ~curl_manager();

        void download_data(const download_type _download_type, const std::string cat_parameter);
    
    private:
        CURL *curl;

        bool curl_auth(const std::string cookies_path, const std::string config_path);
        bool check_config_file(const std::string config_path);
        bool download_manager(std::string &req_url, std::string category, std::string cat_parameter);
        std::string category_selector(const download_type _download_type);
        void log_download_data();

        std::string current_path;

        std::string space_track_user;
        std::string space_track_pwd;
};