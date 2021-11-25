#pragma once
#include <string>
#include <array>
#include "GenericCat.h"

// TODO TRY TO INHERIT FROM COMMONALITIES
const static std::array<std::string, 2> boxCatProp = {
    "COUNTRY",
    "SPADOC_CD"
};

struct BoxUnit : public GenericUnit
{
    std::string country;
};

//inline GenericCat::~GenericCat() {}

class BoxCat : public GenericCat
{
public:
    ~BoxCat() {}
    void setnNewItem(std::string _country) { 
        BoxUnit unit;
        unit.id = getSize() + 1;
        unit.country = _country;
        
        BoxCatVec.push_back(unit);
        setSize(static_cast<unsigned int>(BoxCatVec.size()));
    }

    std::vector<BoxUnit> getBoxCatVec() { return BoxCatVec; }

private:

    std::vector<BoxUnit> BoxCatVec;
};