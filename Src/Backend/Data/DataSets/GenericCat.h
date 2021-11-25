#pragma once

struct GenericUnit {
    unsigned int id;
    bool isValid = true;
};

class GenericCat
{
public:
    virtual ~GenericCat() {};

    int getSize() { return size; };   
    void setSize(size_t _size) { size = _size; }

private:
    unsigned int size = 0;
};