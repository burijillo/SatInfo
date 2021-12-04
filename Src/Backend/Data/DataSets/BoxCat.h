#pragma once
#include "GenericCat.h"
#include <array>
#include <string>

const static std::array<std::string, 12> boxCatProp = {"COUNTRY", "SPADOC_CD", "ORBITAL_TBA",
    "ORBITAL_PAYLOAD_COUNT", "ORBITAL_ROCKET_BODY_COUNT", "ORBITAL_DEBRIS_COUNT",
    "ORBITAL_TOTAL_COUNT", "DECAYED_PAYLOAD_COUNT", "DECAYED_ROCKET_BODY_COUNT",
    "DECAYED_DEBRIS_COUNT", "DECAYED_TOTAL_COUNT", "COUNTRY_TOTAL"};

struct BoxUnit : public GenericUnit {
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
};

class BoxCat : public GenericCat {
public:
    ~BoxCat() {}

    void setnNewItem(std::string _country, std::string _spadoc_cd, std::string _orbital_tba,
        std::string _orbital_payload_count, std::string _orbital_rocket_count,
        std::string _orbital_debris_count, std::string _orbital_total_count,
        std::string _decayed_payload_count, std::string _decayed_rocket_count,
        std::string _decayed_debris_count, std::string _decayed_total_count,
        std::string _country_total) {
        BoxUnit unit;
        unit.id                    = getSize() + 1;
        unit.country               = _country;
        unit.spadoc_cd             = _spadoc_cd;
        unit.orbital_tba           = _orbital_tba;
        unit.orbital_rocket_count  = _orbital_rocket_count;
        unit.orbital_debris_count  = _orbital_debris_count;
        unit.orbital_total_count   = _orbital_total_count;
        unit.decayed_payload_count = _decayed_payload_count;
        unit.decayed_rocket_count  = _decayed_rocket_count;
        unit.decayed_debris_count  = _decayed_debris_count;
        unit.decayed_total_count   = _decayed_total_count;
        unit.country_total         = _country_total;

        // In BoxCat country is name and country_total represents elements
        unit.name     = _country;
        unit.elements = std::stoi(_country_total);

        BoxCatVec.push_back(unit);
        setSize(static_cast<unsigned int>(BoxCatVec.size()));
    }

    BoxUnit getBoxUnit(int index) {
        BoxUnit result;
        if(index > getSize()) {
            result.isValid = false;
            return result;
        } else {
            result = BoxCatVec[index];
        }
        return result;
    }

    std::string getName(int index) override {
        std::string result = "";
        if(index <= getSize()) {
            result = BoxCatVec[index].name;
        }
        return result;
    };

    std::vector<BoxUnit> getBoxCatVec() { return BoxCatVec; }

private:
    std::vector<BoxUnit> BoxCatVec;
};