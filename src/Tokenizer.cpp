/*
 * Copyright 2022, Hutton Grabiel
 */

#include <Tokenizer.h>

std::vector<std::string> Tokenizer::tokenize_line(std::string const& line) {

    std::vector<std::string> tokenized_line;
   
    std::string string_builder;

    size_t line_length = line.length();
    for (size_t i = 0; i <= line_length; i++) {
        if ((line[i] == ' ' || line[i] == ',' || i == line_length) && !string_builder.empty() && string_builder != " ") {
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

std::string Tokenizer::trim_line(std::string& line) {
    Tokenizer::remove_whitespace(line);
    Tokenizer::remove_comments(line);
    return line;
}

std::string Tokenizer::remove_comments(std::string& line) {
    size_t const line_length = line.length();
    size_t comment_index = line_length-1; // EOL in case no comment

    for (size_t i = 0; i < line_length-1; i++) {
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

// Make sure this is called before tokenize_line
std::string Tokenizer::remove_whitespace(std::string& line) {
    // leading whitespace
    size_t leading_index = 0;
    size_t const line_length = line.length();
    for (size_t i = 0; i < line_length; i++) {
        if (line[i] != ' ') {
            leading_index = i;
            break; 
        }
    }
    
    // trailing whitespace
    size_t trailing_index = line.length()-1;
    for (size_t i = trailing_index; i >= 0; i--) {
        if (line[i] != ' ') {
            trailing_index = i;
            break;
        }
    }

    return line.substr(leading_index, trailing_index+1);
}

std::optional<int> Tokenizer::oper_start_index_in_tokenized_line(std::vector<std::string> tokenized_line) {
    std::optional<int> oper_index;
    size_t const tokenized_line_size = tokenized_line.size();

    for (size_t i = 0; i < tokenized_line_size; i++) {
        if (tokenized_line[i][0] == '$' || tokenized_line[i][0] == '#' || tokenized_line[i][0] == '(') {
            oper_index = i;
            return oper_index;
        }
    }

    return {};
}

std::string Tokenizer::oper(std::string oper_token) {
    size_t start_index = 1;

    if (oper_token[0] == '#')
        start_index = 2;
    else if (oper_token[0] == '(') {
        if (oper_token[1] == '#')
            start_index = 3;
        else
            start_index = 2; 
    }
    
    size_t oper_length = oper_token.length()-start_index;

    return oper_token.substr(start_index, oper_length);
}
