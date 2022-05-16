/*
 * Copyright 2022, Hutton Grabiel
 */

#ifndef SYSTEMMONITOR_SYMBOLTABLE_H
#define SYSTEMMONITOR_SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <fstream>

class SymbolTable {
public:
    typedef std::map<const std::string, const int> SymbolTableMap;

    SymbolTable() = default;
    ~SymbolTable() = default;

    static void insert(std::string const&, int);
    static void fill_symbol_table(std::ifstream&);
    [[maybe_unused]] static void print_symbol_table();
    static bool is_label(std::string const&);

    static SymbolTableMap symbol_table;
    static int m_program_counter;
};

#endif //SYSTEMMONITOR_SYMBOLTABLE_H
