#include <catch2/catch_test_macros.hpp>
#include <Tokenizer.h>

TEST_CASE( "Index of Oper in Tokenized Line" ) {
    Tokenizer tokenizer;

    REQUIRE( tokenizer.index_of_oper({"LDA", "$4837", "X"}) == 1 );
    REQUIRE( tokenizer.index_of_oper({"LDA", "#4837", "X"}) == 1 );
    REQUIRE( tokenizer.index_of_oper({"INX"}) == -1 );
    REQUIRE( tokenizer.index_of_oper({"LDA", "($#2837 X)"}) == 1 );
}
