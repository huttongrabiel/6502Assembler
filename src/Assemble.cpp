#include <iostream>
#include <SymbolTable.h>

int main(int argc, char* argv[]) {
    std::ifstream source_code(argv[1]);

    if (!source_code.is_open()) {
        std::cerr <<  "ERROR: File not found. Check file path" << std::endl;
        exit(1);
    }

    SymbolTable s;

    s.fill_symbol_table(source_code);

    s.print_symbol_table();

    source_code.close();

    return 0;    
}
