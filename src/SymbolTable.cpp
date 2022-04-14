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

void SymbolTable::insert(SymbolName symbol_name, ProgramLine program_line) {
    symbol_table.insert(std::pair<SymbolName, ProgramLine>(symbol_name, program_line));
}

void SymbolTable::fill_symbol_table(std::ifstream& source_code) {
    std::string line;

    while (std::getline(source_code, line)) {
        auto const line_length = line.length();
        if (line[line_length-1] == ':') {
            SymbolTable::insert(line.substr(0, line_length-1), program_counter);
        }
        program_counter++;

        Tokenizer t;
        auto trimmed_line = t.remove_whitespace(line);
        trimmed_line = t.remove_comments(trimmed_line);
        std::vector<std::string> tokenized_line = t.tokenize_line(line);

        for (auto const& token : tokenized_line) {
            std::cout << token << " ";
        }

        std::cout << std::endl;
    }
}

void SymbolTable::print_symbol_table() {
    for (auto const& [key, val] : symbol_table) {
        std::cout << key << " : " << val << std::endl;
    }
}
