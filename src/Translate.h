#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <vector>

class Translate {
public:
    Translate();
    ~Translate();
    std::string standardize_instruction(const std::vector<std::string>&);
};

class Helpers {
public:
    Helpers();
    ~Helpers();
    int address_as_int(std::string&);
};

#endif
