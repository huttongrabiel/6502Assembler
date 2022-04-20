#include <iostream>
#include <fstream>
#include <SymbolTable.h>
#include <Tokenizer.h>
#include <Translate.h>

int main(int argc, char* argv[]) {
    std::ifstream source_code(argv[1]);

    if (!source_code.is_open()) {
        std::cerr <<  "ERROR: File not found. Check file path" << std::endl;
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
    symbolTable.print_symbol_table();
    
    // Clear eofbit and seek to 0th position in source file 
    source_code.clear();
    source_code.seekg(0);

    std::string line;

    while (std::getline(source_code, line)) {
        Tokenizer tokenizer;
       
        auto trimmed_line = tokenizer.remove_whitespace(line);
        trimmed_line = tokenizer.remove_comments(trimmed_line);
        std::vector<std::string> const tokenized_line = tokenizer.tokenize_line(trimmed_line);
        
        int const oper_index = tokenizer.index_of_oper_in_tokenized_line(tokenized_line);
        std::string const oper = tokenizer.oper(tokenized_line[oper_index]);

        Translate translate;
    
        // These return -1 when there is no oper found
        int const oper_low_byte = translate.oper_low_byte(oper);
        int const oper_high_byte = translate.oper_high_byte(oper);

        auto const standardized_instruction = translate.standardize_instruction(tokenized_line);
        auto const instruction_hex_opcode = translate.translate_instruction_to_hex_opcode(standardized_instruction);

        std::cout << standardized_instruction << " : " << instruction_hex_opcode << " " << oper_low_byte << " " << oper_high_byte << std::endl;
    }
    
    source_code.close();
    executable.close();

    return 0;    
}
