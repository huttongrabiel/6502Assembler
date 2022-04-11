//
// Created by whuty on 4/9/22.
//

#ifndef SYSTEMMONITOR_SYMBOLTABLE_H
#define SYSTEMMONITOR_SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <fstream>
#include <Tokenizer.h>

class SymbolTable {
public:
    typedef std::map<const std::string, const long long> SymbolTableMap;
    typedef std::string SymbolName;
    typedef long long ProgramLine;

    SymbolTable();
    ~SymbolTable();
    SymbolTableMap symbol_table;
    void insert(SymbolName, ProgramLine);
    void fill_symbol_table(std::ifstream&);
    void print_symbol_table();
private:
    long long program_counter = 0x01;
};

#endif //SYSTEMMONITOR_SYMBOLTABLE_H
