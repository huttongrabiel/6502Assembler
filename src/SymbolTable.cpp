//
// Created by whuty on 4/9/22.
//

#include <SymbolTable.h>
#include <iostream>

SymbolTable::SymbolTable()
{
};

SymbolTable::~SymbolTable()
{
};

void SymbolTable::insert(SymbolName symbol_name, ProgramLine program_line) {
    symbol_table.insert(std::pair<SymbolName, ProgramLine>(symbol_name, program_line));
}