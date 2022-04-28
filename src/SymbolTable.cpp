//
// Created by whuty on 4/9/22.
//

#include <SymbolTable.h>

SymbolTable::SymbolTable()
{
};

SymbolTable::~SymbolTable()
{
};

std::map<const std::string, const int> SymbolTable::symbol_table;
int program_counter;

void SymbolTable::insert(SymbolName symbol_name, ProgramLine program_line) {
    symbol_table.insert({symbol_name, program_line});
}

void SymbolTable::fill_symbol_table(std::ifstream& source_code) {
    std::string line;

    while (std::getline(source_code, line)) {
        if (is_label(line)) { 
            auto const line_length = line.length();
            
            SymbolTable::insert(line.substr(0, line_length-1), program_counter);
            program_counter++;
        }
    }
}

void SymbolTable::print_symbol_table() {
    for (auto const& [key, val] : symbol_table) {
        std::cout << key << " : " << val << std::endl;
    }
}

bool SymbolTable::is_label(std::string line) {
    OpCodes opCodes;
    
    bool has_colon = line[line.length()-1] == ':';
    if (has_colon)
        return true;
    
    return false;
}
