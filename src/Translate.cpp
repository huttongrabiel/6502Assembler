#include <Translate.h>

Translate::Translate()
{
};

Translate::~Translate()
{
};

int Translate::translate_instruction_to_hex_opcode(std::string instruction) {
    OpCodes opCodes;
    if (opCodes.OpCodeMap.find(instruction) != opCodes.OpCodeMap.end()) {
        return opCodes.OpCodeMap.find(instruction)->second;
    }
    return 45; // Arbitrary value that we know we don't want to see
}

std::string Translate::standardize_instruction(const std::vector<std::string>& instruction) {
    //["ADC","$XXXX", "X"]  -> "ADC XXXX,X" which is quickly realized as 0x7D
    
    std::string instruction_builder;

    for (auto const& character : instruction[0]) {
        instruction_builder.push_back(character);
    }
    
    instruction_builder.push_back(' ');
    
    int instruction_one_length = instruction[1].length();    

    for (int i = 0; i < instruction_one_length; i++) {
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

int Translate::oper_low_byte(const std::string oper) {
    int oper_length = oper.length();

    if (oper_length < 2)
        return -1;

    std::string low_byte_string = oper.substr(oper_length-2, 2);

    Helpers helpers;

    int low_byte = helpers.address_as_int(low_byte_string);
    
    // If the oper is a zeropage ($56), we should return 0.
    // $56 is the same as $5600 which means our LSByte is 0.
    if (oper.length() < 4)
        return 0;

    return low_byte;
}

int Translate::oper_high_byte(const std::string oper) {
    if (oper.length() < 2) {
        return -1;
    }

    std::string high_byte_string = oper.substr(0, 2);

    Helpers helpers;

    int high_byte = helpers.address_as_int(high_byte_string);
    
    return high_byte;
}

Helpers::Helpers() 
{
};

Helpers::~Helpers()
{
};

int Helpers::address_as_int(std::string& address) {
    int address_int = 0;
    int multiple = 1; 

    for (int i = address.length()-1; i >= 0; i--) {
        int character_int = address[i] - '0';

        if (character_int >= 0 && character_int <= 9) {
            address_int += character_int * multiple;
            multiple *= 10;
        }
    }
    
    return address_int;
}

std::string Helpers::decimal_to_binary(int decimal_value) {
    if (decimal_value < 0)
        std::cerr << "Decimal Value is negative" << std::endl;

    std::string result = std::bitset<8>(decimal_value).to_string();

    return result;
}
