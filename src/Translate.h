#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <vector>

class Translate {
public:
    Translate();
    ~Translate();
    std::string standardize_instruction(const std::vector<std::string>&);
};

#endif
