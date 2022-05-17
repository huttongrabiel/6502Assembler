/*
 * Copyright 2022, Hutton Grabiel
 */

#include <Translate.h>

int Translate::translate_instruction_to_hex_opcode(std::string const& instruction, int program_counter) {

    auto opcode = OpCodes::OpCodeMap.find(instruction);
    if (opcode != OpCodes::OpCodeMap.end()) {
        return opcode->second;
    }
    else {
        std::cerr << "\033[01;31mERROR: \033[0mAt line " << program_counter << ". \nInstruction " << instruction << " not found." << std::endl;
        return 1;
    }
}

std::string Translate::standardize_instruction(std::vector<std::string> const& instruction) {
    //["ADC","$XXXX", "X"]  -> "ADC XXXX,X" which is quickly realized as 0x7D

    std::string instruction_builder;

    for (auto const& character : instruction[0]) {
        instruction_builder.push_back(character);
    }
    
    if (TranslationHelpers::is_branch_instruction(instruction_builder))
        return instruction_builder;

    if (instruction.size() <= 1)
        return instruction_builder;
    
    instruction_builder.push_back(' ');
    
    size_t instruction_one_length = instruction[1].length();

    for (size_t i = 0; i < instruction_one_length; i++) {
        if (instruction[1][i] == '#') {
            instruction_builder.push_back(instruction[1][i]);
            return instruction_builder; // Full stop if immediate addressing.
        }
        else if (instruction[1][i] == '(' || instruction[1][i] == '$') {
            instruction_builder.push_back(instruction[1][i]);
            continue;
        }
        instruction_builder.push_back('X');
    }
    
    if (instruction.size() == 2) {
        return instruction_builder;
    }

    instruction_builder.push_back(' ');
    
    for (auto const& character : instruction[2]) {
        instruction_builder.push_back(character);
    }

    return instruction_builder;
}

int Translate::oper_low_byte(std::string const& oper) {
    size_t oper_length = oper.length();

    if (oper_length < 2)
        return -1;

    std::string low_byte_string = oper.substr(oper_length-2, 2);

    int low_byte = TranslationHelpers::address_as_int(low_byte_string);
    
    // If the oper is a zeropage ($56), we should return 0.
    // $56 is the same as $5600 which means our LSByte is 0.
    if (oper.length() < 4)
        return 0;

    return low_byte;
}

int Translate::oper_high_byte(std::string const& oper) {
    if (oper.length() < 2) {
        return -1;
    }

    std::string high_byte_string = oper.substr(0, 2);

    int high_byte = TranslationHelpers::address_as_int(high_byte_string);
    
    return high_byte;
}

std::string Translate::label_address_binary(std::vector<std::string> const& branch_instruction, int program_counter) {
    auto const label = branch_instruction[1];

    auto const label_address = SymbolTable::symbol_table.find(label);

    if (label_address == SymbolTable::symbol_table.end()) {
        std::string string_builder;
        for (auto const& token : branch_instruction) {
            string_builder += token;
            string_builder += " ";
        }
        std::cerr << "\033[01;31mERROR: \033[0mAt line " << program_counter << ". \nLabel " << label << " not found in instruction:\n     '" << string_builder << "'" << std::endl;
        std::cerr << "Did you forget to create this label?" << std::endl;
        exit(1);
    }

    std::string binary_address = TranslationHelpers::decimal_to_binary(label_address->second);
    
    return binary_address;
}

int TranslationHelpers::address_as_int(std::string const& address) {
    return std::stoi(address,nullptr,16);
}

std::string TranslationHelpers::decimal_to_binary(int decimal_value) {
    if (decimal_value < 0) {
        std::cerr << "Decimal Value is negative" << std::endl;
    }

    std::string result = std::bitset<8>(decimal_value).to_string();

    return result;
}

bool TranslationHelpers::is_branch_instruction(std::string const& instruction) {
    std::set<std::string> branch_instructions {"BPL", "BMI", "BVC", "BVS", "BCC", "BCS", "BNE", "BEQ"};
    
    if (branch_instructions.count(instruction))
        return true;

    return false;
}