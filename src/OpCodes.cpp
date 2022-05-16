/*
 * Copyright 2022, Hutton Grabiel
 */

#include <OpCodes.h>

std::map<const std::string, const int> OpCodes::OpCodeMap = {
    {"ADC #", 0x69},             // immediate
    {"ADC $XX", 0x65},           // zeropage
    {"ADC $XX X", 0x75},         // zeropage,X
    {"ADC $XXXX", 0x6D},         // absolute 
    {"ADC $XXXX X", 0x7D},       // absolute,X 
    {"ADC $XXXX Y", 0x79},       // absolute,Y
    {"ADC ($XXXX X)", 0x61},     // (indirect,X)
    {"ADC ($XXXX) Y", 0x70},     // (indirect),Y

    {"AND #", 0x29},
    {"AND $XX", 0x25},
    {"AND $XX X", 0x35},
    {"AND $XXXX", 0x2D},
    {"AND $XXXX X", 0x3D},
    {"AND $XXXX Y", 0x39},
    {"AND ($XXXX X)", 0x21},
    {"AND ($XXXX),Y)", 0x31},

    {"ASL A", 0x0A},
    {"ASL $XX", 0x06},
    {"ASL $XX X", 0x16},
    {"ASL $XXXX", 0x0E},
    {"ASL $XXXX X", 0x1E},
    
    {"BCC", 0x90},

    {"BCS", 0xB0},
    
    {"BEQ", 0xF0},

    {"BIT $XX", 0x24},
    {"BIT $XXXX", 0x2C},

    {"BMI", 0x30},

    {"BNE", 0xD0},

    {"BPL", 0x10},

    {"BRK", 0x00},

    {"BVC", 0x50},

    {"BVS", 0x70},

    {"CLC", 0x18},

    {"CLD", 0xD8},

    {"CLI", 0x58},

    {"CLV", 0xB8},

    {"CMP #", 0xC9},
    {"CMP $XX", 0xC5},
    {"CMP $XX X", 0xD5},
    {"CMP $XXXX", 0xCD},
    {"CMP $XXXX X", 0xDD},
    {"CMP $XXXX Y", 0xD9},
    {"CMP ($XXXX X)", 0xC1},
    {"CMP ($XXXX),Y)", 0xD1},

    {"CPX #", 0xE0},
    {"CPX $XX", 0xE4},
    {"CPX $XXXX", 0xEC},

    {"CPY #", 0xC0},
    {"CPY $XX", 0xC4},
    {"CPY $XXXX", 0xCC},

    {"DEC $XX", 0xC6},
    {"DEC $XX X", 0xD6},
    {"DEC $XXXX", 0xCE},
    {"DEC $XXXX X", 0xDE},

    {"DEX", 0xCA},

    {"DEY", 0x88},

    {"EOR #", 0x49},
    {"EOR $XX", 0x45},
    {"EOR $XX X", 0x55},
    {"EOR $XXXX", 0x4D},
    {"EOR $XXXX X", 0x5D},
    {"EOR $XXXX Y", 0x59},
    {"EOR ($XXXX X)", 0x41},
    {"EOR ($XXXX),Y)", 0x51},

    {"INC $XX", 0xE6},
    {"INC $XX X", 0xF6},
    {"INC $XXXX", 0xEE},
    {"INC $XXXX X", 0xFE},

    {"INX", 0xE8},

    {"INY", 0xC8},

    {"JMP $XXXX", 0x4C},
    {"JMP ($XXXX)", 0x6C},

    {"LDA #", 0xA9},
    {"LDA $XX", 0xA5},
    {"LDA $XX X", 0xB5},
    {"LDA $XXXX", 0xAD},
    {"LDA $XXXX X", 0xBD},
    {"LDA $XXXX Y", 0xB9},
    {"LDA ($XXXX X)", 0xA1},
    {"LDA ($XXXX),Y)", 0xB1},

    {"LDX #", 0xA2},
    {"LDX $XX", 0xA6},
    {"LDX $XX Y", 0xB6},
    {"LDX $XXXX", 0xAE},
    {"LDX $XXXX Y", 0xBE},

    {"LDY #", 0xA0},
    {"LDY $XX", 0xA4},
    {"LDY $XX X", 0xB4},
    {"LDY $XXXX", 0xAC},
    {"LDY $XXXX X", 0xBC},

    {"LSR A", 0x4A},
    {"LSR $XX", 0x46},
    {"LSR $XX X", 0x56},
    {"LSR $XXXX", 0x4E},
    {"LSR $XXXX X", 0x5E},
    
    // Don't fall victim to a NOP slide ya noob :) 
    {"NOP", 0xEA},

    {"ORA #", 0x09},
    {"ORA $XX", 0x05},
    {"ORA $XX X", 0x15},
    {"ORA $XXXX", 0x0D},
    {"ORA $XXXX X", 0x1D},
    {"ORA $XXXX Y", 0x19},
    {"ORA ($XXXX X)", 0x01},
    {"ORA ($XXXX),Y)", 0x11},

    {"PHA", 0x48},

    {"PHP", 0x08},

    {"PLA", 0x68},

    {"PLP", 0x28},

    {"ROL A", 0x2A},
    {"ROL $XX", 0x26},
    {"ROL $XX X", 0x36},
    {"ROL $XXXX", 0x2E},
    {"ROL $XXXX X", 0x3E},
 
    {"ROR A", 0x6A},
    {"ROR $XX", 0x66},
    {"ROR $XX X", 0x76},
    {"ROR $XXXX", 0x6E},
    {"ROR $XXXX X", 0x7E},

    {"RTI", 0x40},

    {"RTS", 0x60},

    {"SBC #", 0xE9},
    {"SBC $XX", 0xE5},
    {"SBC $XX X", 0xF5},
    {"SBC $XXXX", 0xED},
    {"SBC $XXXX X", 0xFD},
    {"SBC $XXXX Y", 0xF9},
    {"SBC ($XXXX X)", 0xE1},
    {"SBC ($XXXX),Y)", 0xF1},

    {"SEC", 0x38},
    
    {"SED", 0xF8},

    {"SEI", 0x78},

    {"STA $XX", 0x85},
    {"STA $XX X", 0x95},
    {"STA $XXXX", 0x8D},
    {"STA $XXXX X", 0x9D},
    {"STA $XXXX Y", 0x99},
    {"STA ($XXXX X)", 0x81},
    {"STA ($XXXX),Y)", 0x91},
    
    {"STX $XX", 0x86},
    {"STX $XX Y", 0x96},
    {"STX $XXXX", 0x8E},
    
    {"STY $XX", 0x84},
    {"STY $XX X", 0x94},
    {"STY $XXXX", 0x8C},

    {"TAX", 0xAA},

    {"TAY", 0xA8},

    {"TSX", 0xBA},

    {"TXA", 0x8A},

    {"TXS", 0x9A},

    {"TYA", 0x98}

};
