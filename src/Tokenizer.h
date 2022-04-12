#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>

class Tokenizer {
public:
    Tokenizer();
    ~Tokenizer();
    std::vector<std::string> tokenize_line(std::string);
    void remove_comments(std::string&);
    std::string remove_whitespace(std::string);
};

#endif
