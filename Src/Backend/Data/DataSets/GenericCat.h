#pragma once

struct GenericUnit {
    unsigned int id;
    bool         isValid = true;

    std::string name;
    int         elements;
};

class GenericCat {
public:
    virtual ~GenericCat() {};
    GenericCat() {};

    int  getSize() { return size; };
    void setSize(size_t _size) { size = _size; }

    virtual std::string getName(int index) = 0;

private:
    unsigned int size = 0;
};