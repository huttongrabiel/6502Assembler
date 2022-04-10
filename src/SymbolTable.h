//
// Created by whuty on 4/9/22.
//

#ifndef SYSTEMMONITOR_SYMBOLTABLE_H
#define SYSTEMMONITOR_SYMBOLTABLE_H

#include <iostream>
#include <map>

class SymbolTable {
    typedef std::map<const std::string, const long long> SymbolTableMap;
    typedef std::string SymbolName;
    typedef long long ProgramLine;

    SymbolTable();
    ~SymbolTable();
    SymbolTableMap symbol_table;
    void push_back(SymbolName);
    void insert(SymbolName, ProgramLine);
};

#endif //SYSTEMMONITOR_SYMBOLTABLE_H
