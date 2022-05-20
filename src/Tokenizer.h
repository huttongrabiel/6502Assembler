/*
 * Copyright 2022, Hutton Grabiel
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>

class Tokenizer {
public:
    Tokenizer() = default;
    ~Tokenizer() = default;

    static std::vector<std::string> tokenize_line(std::string const&);
    static std::string trim_line(std::string&);
    static int oper_start_index_in_tokenized_line(std::vector<std::string> tokenized_line);
    static std::string oper(std::string);

private:
    static std::string remove_comments(std::string&);
    static std::string remove_whitespace(std::string&);
};

#endif
