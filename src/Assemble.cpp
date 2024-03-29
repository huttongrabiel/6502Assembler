/*
 * Copyright 2022, Hutton Grabiel
 */

#include <iostream>
#include <SymbolTable.h>
#include <Tokenizer.h>
#include <Translate.h>
#include <cstring>
#include <optional>

int main(int argc, char* argv[]) {
    std::ifstream source_code(argv[1]);

    if (!source_code.is_open()) {
        std::cerr <<  "\033[1;31mERROR: \033[0mFile '" << argv[1] << "' not found. Check file path." << std::endl;
        exit(1);
    }
    
    if (!argv[2]) {
        std::cerr << "\033[1;31mERROR: \033[0mNo executable file name provided. Assembler requires three arguments total." << std::endl;
        exit(1);
    }

    bool hexdump = false;
    if (argv[3] && strcmp(argv[3], "--hexdump") == 0) {
        hexdump = true;
    }
    
    std::string binary_file_name = argv[2]; 
    std::ofstream executable(binary_file_name);

    // Add label key values to symbol_table
    SymbolTable::fill_symbol_table(source_code);

    // Reset the .asm file to read starting at 0th position
    source_code.clear();
    source_code.seekg(0);

    SymbolTable::m_program_counter = 1;
    unsigned long long memory_address = 0x800;

    std::string buffer;
    while (std::getline(source_code, buffer)) {

        // Skip lines that are labels or blank
        if (SymbolTable::is_label(buffer) || Translate::is_blank_line(buffer) || buffer.empty()) {
            SymbolTable::m_program_counter++;
            continue;
        }

        // Lines 46-55 parse the line into usable variables
        auto trimmed_line = Tokenizer::trim_line(buffer);
        std::vector<std::string> const tokenized_line = Tokenizer::tokenize_line(trimmed_line);

        std::optional<int> const oper_index = Tokenizer::oper_start_index_in_tokenized_line(tokenized_line);

        auto const standardized_instruction = Translate::standardize_instruction(tokenized_line);
        int const instruction_opcode = Translate::translate_instruction_to_hex_opcode(standardized_instruction, SymbolTable::m_program_counter);
        std::string binary_instruction_opcode = Translate::decimal_to_binary(instruction_opcode);

        if (hexdump) {
            std::cout << std::hex << "0x" << memory_address << ": ";
            std::cout << std::hex << instruction_opcode << " ";
        }

        executable << binary_instruction_opcode << std::endl;

        if (oper_index.has_value()) {
            std::string const oper = Tokenizer::oper(tokenized_line[oper_index.value()]);
            std::optional<int> const oper_low_byte = Translate::oper_byte(oper, Translate::OperByte::Low);
            std::optional<int> const oper_high_byte = Translate::oper_byte(oper, Translate::OperByte::High);

            if (oper_low_byte.has_value() || (oper_low_byte.has_value() && oper_high_byte.has_value())) {
                std::string const oper_low_byte_binary = Translate::decimal_to_binary(oper_low_byte.value());
                executable << oper_low_byte_binary << std::endl;
                if (hexdump)
                    std::cout << std::hex << oper_low_byte.value() << " ";
            }

            if (oper_high_byte.has_value()) {
                std::string const oper_high_byte_binary = Translate::decimal_to_binary(oper_high_byte.value());
                executable << oper_high_byte_binary << std::endl;
                if (hexdump)
                    std::cout << std::hex << oper_high_byte.value() << std::endl;
            }
        }

        // Branch instructions are handled separately due to the need to lookup the label in the symbol table
        if (Translate::is_branch_instruction(tokenized_line[0])) {
            std::string const binary_address_of_label = Translate::label_address_binary(tokenized_line, SymbolTable::m_program_counter);
            executable << binary_address_of_label << std::endl;

            auto label_address = SymbolTable::symbol_table.find(tokenized_line[1]);
            if (label_address != SymbolTable::symbol_table.end() && hexdump) {
                // FIXME: Print high/low byte instead of just the whole byte. This requires figuring out how to
                // do it...
                std::cout << std::hex << label_address->second << std::endl;
            }
        }

        SymbolTable::m_program_counter++;
        memory_address++;

    }
    
    source_code.close();
    executable.close();

    return 0;    
}
