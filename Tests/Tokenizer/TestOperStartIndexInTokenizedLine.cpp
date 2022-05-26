#include <catch2/catch_test_macros.hpp>
#include <Tokenizer.h>

TEST_CASE( "Index of Oper in Tokenized Line" ) {
    REQUIRE( Tokenizer::oper_start_index_in_tokenized_line({"LDA", "$4837", "X"}) == 1 );
    REQUIRE( Tokenizer::oper_start_index_in_tokenized_line({"LDA", "#4837", "X"}) == 1 );
    REQUIRE( Tokenizer::oper_start_index_in_tokenized_line({"INX"}).has_value() == false );
    REQUIRE( Tokenizer::oper_start_index_in_tokenized_line({"LDA", "($#2837 X)"}) == 1 );
}
