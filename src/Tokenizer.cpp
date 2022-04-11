#include <Tokenizer.h>

Tokenizer::Tokenizer()
{
};

Tokenizer::~Tokenizer()
{
};

std::vector<std::string> Tokenizer::tokenize_line(std::string line) {
    // ADC $4400, X -> ["ADC","$4400","X"]
    //                   ---           -  ADC X -> 7D
   
    std::vector<std::string> tokenized_line;
   
    std::string string_builder = ""; 

    int line_length = line.length();
    for (int i = 0; i < line_length; i++) {
        if ((line[i] == ' ' || line[i] == ',') && (string_builder != "" && string_builder != " ")) {
            tokenized_line.push_back(string_builder);
            string_builder = "";
            continue;
        }
        string_builder.push_back(line[i]);
    }

    return tokenized_line;
}
