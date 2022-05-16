/*
 * Copyright 2022, Hutton Grabiel
 */

#include <SymbolTable.h>

int SymbolTable::m_program_counter = 1;
std::map<const std::string, const int> SymbolTable::symbol_table;

void SymbolTable::insert(std::string const& symbol_name, int const program_line) {
    SymbolTable::symbol_table.insert({symbol_name, program_line});
}

void SymbolTable::fill_symbol_table(std::ifstream& source_code) {
    std::string buffer;
    while (std::getline(source_code, buffer)) {

        if (is_label(buffer)) {
            auto const line_length = buffer.length();
            SymbolTable::insert(buffer.substr(0, line_length-1), SymbolTable::m_program_counter);
        }

        SymbolTable::m_program_counter++;
    }
}

void SymbolTable::print_symbol_table() {
    for (auto const& [key, val] : symbol_table) {
        std::cout << key << " : " << val << std::endl;
    }
}

bool SymbolTable::is_label(std::string const& line) {
    bool has_colon = line[line.length()-1] == ':';
    if (has_colon)
        return true;
    
    return false;
}
