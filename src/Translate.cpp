#include <Translate.h>

Translate::Translate()
{
};

Translate::~Translate()
{
};

int Translate::translate_instruction_to_hex_opcode(std::string instruction, int program_counter) {

    OpCodes opCodes;

    auto opcode = opCodes.OpCodeMap.find(instruction);
    if (opcode != opCodes.OpCodeMap.end()) {
        return opcode->second;
    }
    else {
         //FIXME: Does not print the correct line at which the error occured (always prints 1).
        std::cerr << "ERROR: Instruction " << instruction << " not found at line - " << std::endl;
        std::cerr << "If the offending line is a branch instruction, check that you created the label." 
                        " If the offending line is an instruction, check your spelling and syntax for that instruction" << std::endl;
        return 1;
    }
}

std::string Translate::standardize_instruction(const std::vector<std::string>& instruction) {
    //["ADC","$XXXX", "X"]  -> "ADC XXXX,X" which is quickly realized as 0x7D
    TranslationHelpers translationHelpers;

    std::string instruction_builder;

    for (auto const& character : instruction[0]) {
        instruction_builder.push_back(character);
    }
    
    if (translationHelpers.is_branch_instruction(instruction_builder))
        return instruction_builder;

    if (instruction.size() <= 1)
        return instruction_builder;
    
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

    TranslationHelpers translationHelpers;

    int low_byte = translationHelpers.address_as_int(low_byte_string);
    
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

    TranslationHelpers translationHelpers;

    int high_byte = translationHelpers.address_as_int(high_byte_string);
    
    return high_byte;
}

std::string Translate::label_address_binary(const std::vector<std::string> branch_instruction, int program_counter) {
    SymbolTable symbolTable;
    TranslationHelpers translationHelpers;
    
    auto const label = branch_instruction[1];

    auto const label_address = symbolTable.symbol_table.find(label);

    if (label_address == symbolTable.symbol_table.end()) {
        std::string string_builder = "";
        for (auto const token : branch_instruction) {
            string_builder += token;
            string_builder += " ";
        }
        std::cerr << "ERROR at line " << symbolTable.m_program_counter-1 << ". \nLabel " << label << " not found in instruction:\n     '" << string_builder << "'" << std::endl;
        std::cerr << "Did you forget to create this label?" << std::endl;
        exit(1);
    }

    std::string const binary_address = translationHelpers.decimal_to_binary(label_address->second);
    
    return binary_address;
}

TranslationHelpers::TranslationHelpers() 
{
};

TranslationHelpers::~TranslationHelpers()
{
};

int TranslationHelpers::address_as_int(std::string address) {
    int address_int = 0;
    int multiple = 1; 

    for (int i = address.length()-1; i >= 0; i--) {
        int character_int = address[i] - '0';

        if (character_int >= 0 && character_int <= 9) {
            address_int += character_int * multiple;
            multiple *= 10;
        }
    }
    
    return std::stoi(address,0,16);
}

std::string TranslationHelpers::decimal_to_binary(int decimal_value) {
    if (decimal_value < 0) {
        std::cerr << "Decimal Value is negative" << std::endl;
    }

    std::string result = std::bitset<8>(decimal_value).to_string();

    return result;
}

bool TranslationHelpers::is_branch_instruction(std::string instruction) {
    std::set<std::string> branch_instructions {"BPL", "BMI", "BVC", "BVS", "BCC", "BCS", "BNE", "BEQ"};
    
    if (branch_instructions.count(instruction))
        return true;

    return false;
}
