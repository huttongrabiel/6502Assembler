//
// Created by whuty on 4/9/22.
//

#ifndef SYSTEMMONITOR_SYMBOLTABLE_H
#define SYSTEMMONITOR_SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <fstream>
#include <Tokenizer.h>
#include <Translate.h>

class SymbolTable {
public:
    typedef std::map<const std::string, const int> SymbolTableMap;
    typedef std::string SymbolName;
    typedef int ProgramLine;

    SymbolTable();
    ~SymbolTable();

    void insert(SymbolName, ProgramLine);
    void fill_symbol_table(std::ifstream&);
    void print_symbol_table();
    bool is_label(std::string);

    static SymbolTableMap symbol_table;
    static int m_program_counter;
};

#endif //SYSTEMMONITOR_SYMBOLTABLE_H
