#include <iostream>
#include <fstream>
#include <SymbolTable.h>
#include <Tokenizer.h>
#include <Translate.h>

int main(int argc, char* argv[]) {
    std::ifstream source_code(argv[1]);

    if (!source_code.is_open()) {
        std::cerr <<  "ERROR: File '" << argv[1] << "' not found. Check file path." << std::endl;
        exit(1);
    }
    
    if (!argv[2]) {
        std::cerr << "ERROR: No executable file name provided. Assembler requires three arguments total." << std::endl;
        exit(1);
    }
    
    std::string binary_file_name = argv[2]; 
    std::ofstream executable(binary_file_name);

    Translate translate;
    TranslationHelpers translationHelpers;

    // Add label key values to symbol_table
    SymbolTable::fill_symbol_table(source_code);

    // Reset the .asm file to read starting at 0th position
    source_code.clear();
    source_code.seekg(0);

    SymbolTable::m_program_counter = 1;

    std::string buffer;
    while (std::getline(source_code, buffer)) {

        // Labels are already handled in earlier fill_symbol_table call
        if (SymbolTable::is_label(buffer)) {
            SymbolTable::m_program_counter++;
            continue;
        }

        // Lines 46-55 parse the line into usable variables
        auto trimmed_line = Tokenizer::remove_whitespace(buffer);
        trimmed_line = Tokenizer::remove_comments(trimmed_line);
        std::vector<std::string> const tokenized_line = Tokenizer::tokenize_line(trimmed_line);

        int const oper_index = Tokenizer::oper_start_index_in_tokenized_line(tokenized_line);

        auto const standardized_instruction = translate.standardize_instruction(tokenized_line);
        int const instruction_opcode = translate.translate_instruction_to_hex_opcode(standardized_instruction, SymbolTable::m_program_counter);
        std::string binary_instruction_opcode = translationHelpers.decimal_to_binary(instruction_opcode);

        executable << binary_instruction_opcode << std::endl;

        // oper_index returns -1 if no oper is found
        if (oper_index != -1) {
            std::string const oper = Tokenizer::oper(tokenized_line[oper_index]);
            int const oper_low_byte = translate.oper_low_byte(oper);
            int const oper_high_byte = translate.oper_high_byte(oper);

            // oper_low_byte and oper_high_byte return -1 if there is no oper
        
            if (oper_low_byte > 0) {
                std::string const oper_low_byte_binary = translationHelpers.decimal_to_binary(oper_low_byte);
                executable << oper_low_byte_binary << std::endl;
            }

            if (oper_high_byte > 0) {
                std::string const oper_high_byte_binary = translationHelpers.decimal_to_binary(oper_high_byte);
                executable << oper_high_byte_binary << std::endl;
            }
        }

        // Branch instructions are handled separately due to the need to lookup the label in the symbol table
        if (translationHelpers.is_branch_instruction(tokenized_line[0])) {
            std::string const binary_address_of_label = translate.label_address_binary(tokenized_line, SymbolTable::m_program_counter);
            executable << binary_address_of_label << std::endl;
        }

        SymbolTable::m_program_counter++;

    }
    
    source_code.close();
    executable.close();

    return 0;    
}
