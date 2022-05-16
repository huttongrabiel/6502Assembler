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

    SymbolTable symbolTable;
    
    symbolTable.fill_symbol_table(source_code);

    // Clear eofbit and seek to 0th position in source file 
    source_code.clear();
    source_code.seekg(0);

    std::string line;

    Tokenizer tokenizer;
    Translate translate;
    TranslationHelpers translationHelpers;

    SymbolTable::m_program_counter = 1;

    while (std::getline(source_code, line)) {

        if (symbolTable.is_label(line)) {
            SymbolTable::m_program_counter++;
            continue;
        }

        auto trimmed_line = tokenizer.remove_whitespace(line);
        trimmed_line = tokenizer.remove_comments(trimmed_line);
        std::vector<std::string> const tokenized_line = tokenizer.tokenize_line(trimmed_line);

        int const oper_index = tokenizer.index_of_oper_in_tokenized_line(tokenized_line);

        auto const standardized_instruction = translate.standardize_instruction(tokenized_line);
        int const instruction_opcode = translate.translate_instruction_to_hex_opcode(standardized_instruction, SymbolTable::m_program_counter); // returns a hex value, not decimal
        std::string instruction_binary_opcode = translationHelpers.decimal_to_binary(instruction_opcode);

        executable << instruction_binary_opcode << std::endl;
        
        if (oper_index != -1) {
            std::string const oper = tokenizer.oper(tokenized_line[oper_index]);
            // These return -1 when there is no oper found
            int const oper_low_byte = translate.oper_low_byte(oper);
            int const oper_high_byte = translate.oper_high_byte(oper);
        
            if (oper_low_byte > 0) {
                std::string const oper_low_byte_binary = translationHelpers.decimal_to_binary(oper_low_byte);
                executable << oper_low_byte_binary << std::endl;
            }

            if (oper_high_byte > 0) {
                std::string const oper_high_byte_binary = translationHelpers.decimal_to_binary(oper_high_byte);
                executable << oper_high_byte_binary << std::endl;
            }
        }

        if (translationHelpers.is_branch_instruction(tokenized_line[0])) {
            std::string const label_address_binary = translate.label_address_binary(tokenized_line, SymbolTable::m_program_counter);
            executable << label_address_binary << std::endl;
        }

        SymbolTable::m_program_counter++;

    }
    
    source_code.close();
    executable.close();

    return 0;    
}
