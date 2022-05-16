/*
 * Copyright 2022, Hutton Grabiel
 */

#ifndef INC_6502ASSEMBLER_OPCODES_H
#define INC_6502ASSEMBLER_OPCODES_H

#include <map>

class OpCodes {
public: 
    OpCodes() = default;
    ~OpCodes() = default;
    static std::map<const std::string, const int> OpCodeMap;
};

#endif //INC_6502ASSEMBLER_OPCODES_H
