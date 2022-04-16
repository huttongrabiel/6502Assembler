#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <vector>
#include <OpCodes.h>

class Translate {
public:
    Translate();
    ~Translate();
    int translate_instruction_to_hex_opcode(std::string);
    std::string standardize_instruction(const std::vector<std::string>&);
};

class Helpers {
public:
    Helpers();
    ~Helpers();
    int address_as_int(std::string&);
};

#endif
