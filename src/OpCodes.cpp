//
// Created by whuty on 4/9/22.
//

#include <OpCodes.h>

OpCodes::OpCodeMap = {
    {"ADC #", 0x69},            // immediate
    {"ADC oper", 0x65},         // zeropage
    {"ADC oper,X", 0x75},       // zeropage,X
    {"ADC oper", 0x6D},         // absolute 
    {"ADC oper,X", 0x7D},       // absolute,X 
    {"ADC oper,Y", 0x79},       // absolute,Y
    {"ADC (oper,X)", 0x61},     // (indirect,X)
    {"ADC (oper),Y", 0x71},     // (indirect),Y


};
