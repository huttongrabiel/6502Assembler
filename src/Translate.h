/*
 * Copyright 2022, Hutton Grabiel
 */

#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <vector>
#include <OpCodes.h>
#include <bitset>
#include <set>
#include <SymbolTable.h>

class Translate {
public:
    Translate() = default;
    ~Translate() = default;

    enum class OperByte {
        High,
        Low
    };

    static int translate_instruction_to_hex_opcode(std::string const&, int);
    static std::string standardize_instruction(std::vector<std::string> const&);
    static int oper_byte(std::string, OperByte);
    static std::string label_address_binary(std::vector<std::string> const&, int);
};

class TranslationHelpers : public Translate {
public:
    TranslationHelpers() = default;
    ~TranslationHelpers() = default;
    static int address_as_int(std::string const&);
    static std::string decimal_to_binary(int);
    static bool is_branch_instruction(std::string const&);
};

#endif
