//
// Created by whuty on 4/9/22.
//

#ifndef INC_6502ASSEMBLER_OPCODES_H
#define INC_6502ASSEMBLER_OPCODES_H

#include <vector>
#include <map>
#include <iostream>

class OpCodes {
public: 
    OpCodes();
    ~OpCodes();
    static std::map<const std::string, const int> OpCodeMap;
};

#endif //INC_6502ASSEMBLER_OPCODES_H
