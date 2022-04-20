#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <vector>
#include <OpCodes.h>
#include <bitset>

class Translate {
public:
    Translate();
    ~Translate();
    int translate_instruction_to_hex_opcode(std::string);
    std::string standardize_instruction(const std::vector<std::string>&);
    int oper_low_byte(const std::string);
    int oper_high_byte(const std::string);
};

class TranslationHelpers : public Translate {
public:
    TranslationHelpers();
    ~TranslationHelpers();
    int address_as_int(std::string);
    std::string decimal_to_binary(int);
};

#endif
