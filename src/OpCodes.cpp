//
// Created by whuty on 4/9/22.
//

#include <OpCodes.h>

OpCodes::OpCodeMap = {
    {"ADC #", 0x69},            // immediate
    {"ADC XX", 0x65},         // zeropage
    {"ADC XX,X", 0x75},       // zeropage,X
    {"ADC XXXX", 0x6D},         // absolute 
    {"ADC XXXX X", 0x7D},       // absolute,X 
    {"ADC XXXX Y", 0x79},       // absolute,Y
    {"ADC (XXXX X)", 0x61},     // (indirect,X)
    {"ADC (XXXX) Y", 0x71},     // (indirect),Y
};
