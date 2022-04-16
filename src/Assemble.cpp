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
        std::vector<std::string> tokenized_line = tokenizer.tokenize_line(trimmed_line);
        
        Translate translate;
        auto const standardized_instruction = translate.standardize_instruction(tokenized_line);
        auto const translated_instruction = translate.translate_instruction_to_hex_opcode(standardized_instruction);
        
        std::cout << standardized_instruction << " : " << translated_instruction << std::endl;
    }

    source_code.close();

    return 0;    
}
