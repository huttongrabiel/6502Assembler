#include <Tokenizer.h>

Tokenizer::Tokenizer()
{
};

Tokenizer::~Tokenizer()
{
};

std::vector<std::string> Tokenizer::tokenize_line(std::string line) {

    std::vector<std::string> tokenized_line;
   
    std::string string_builder = ""; 

    int line_length = line.length();
    for (int i = 0; i <= line_length; i++) {
        if ((line[i] == ' ' || line[i] == ',' || i == line_length) && string_builder != "" && string_builder != " ") {
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

// Make sure this is called before tokenize_line
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

// Returns the index of the oper (address) in the toknized instruction.
// If the instruction does not have an oper (ie. INX) the return value
// is -1.
int Tokenizer::index_of_oper_in_tokenized_line(std::vector<std::string> tokenized_line) {
    int oper_index = -1;
    int tokenized_line_size = tokenized_line.size(); 

    for (int i = 0; i < tokenized_line_size; i++) {
        if (tokenized_line[i][0] == '$' || tokenized_line[i][0] == '#')
            oper_index = i;
        else if (tokenized_line[i][0] == '(') 
            oper_index = i;
    }

    return oper_index;
}

std::string Tokenizer::oper(std::string oper_token) {
    int start_index = 1;

    if (oper_token[0] == '#')
        start_index = 2;
    else if (oper_token[0] == '(') {
        start_index = 3; 
    }
    
    int oper_length = oper_token.length()-start_index;

    return oper_token.substr(start_index, oper_length);
}
