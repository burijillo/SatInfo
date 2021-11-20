#pragma once
#include <string>
#include <array>

const static std::array<std::string, 2> boxCatProp = {
    "COUNTRY",
    "SPADOC_CD"
};

class BoxCat
{
public:
    BoxCat(std::string _country) {
        country = _country;
    }

    std::string getCountry() { return country; }
private:

    std::string country;
};