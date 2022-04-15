#include <Translate.h>

Translate::Translate()
{
};

Translate::~Translate()
{
};

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
