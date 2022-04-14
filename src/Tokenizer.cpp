#include <Tokenizer.h>

Tokenizer::Tokenizer()
{
};

Tokenizer::~Tokenizer()
{
};

// split line into tokens
std::vector<std::string> Tokenizer::tokenize_line(std::string line) {
    // ADC $4400, X -> ["ADC","$4400","X"]
    //                   ---           -  ADC X -> 7D
   
    std::vector<std::string> tokenized_line;
   
    std::string string_builder = ""; 

    int line_length = line.length();
    for (int i = 0; i < line_length; i++) {
        if ((line[i] == ' ' || line[i] == ',' || i == line_length-1) && string_builder != "" && string_builder != " ") {
            tokenized_line.push_back(string_builder);
            string_builder = "";
            continue;
        }
        if (line[i] != ' ') {
            string_builder.push_back(line[i]);
        }
    }

    return tokenized_line;
}

std::string Tokenizer::remove_comments(std::string line) {
    int line_length = line.length();
    int comment_index = line_length-1; // EOL in case no comment

    for (int i = 0; i < line_length-1; i++) {
        if (line[i] == ';') {
            comment_index = i;
            break;
        }
    }

    if (comment_index == 0) {
        line = "";
    }

    line = line.substr(0, comment_index+1);

    return(line);
}

// remove leading whitespace from line
// call before tokenize_line
std::string Tokenizer::remove_whitespace(std::string line) {
    // leading whitespace
    int leading_index = 0;
    int line_length = line.length();
    for (int i = 0; i < line_length; i++) {
        if (line[i] != ' ') {
            leading_index = i;
            break; 
        }
    }
    
    // trailing whitespace
    int trailing_index = line.length()-1;
    for (int i = trailing_index; i >= 0; i--) {
        if (line[i] != ' ') {
            trailing_index = i;
            break;
        }
    }

    return line.substr(leading_index, trailing_index+1);
}
