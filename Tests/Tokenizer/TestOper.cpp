#include <catch2/catch_test_macros.hpp>
#include <Tokenizer.h>

TEST_CASE( "Oper (ie 4843) of the instruction" ) {
    REQUIRE( Tokenizer::oper("#$8473") == "8473" );
    REQUIRE( Tokenizer::oper("$2218") == "2218" );
    REQUIRE( Tokenizer::oper("$2810") == "2810" );
    REQUIRE( Tokenizer::oper("$28") == "28" );
    REQUIRE( Tokenizer::oper("($9823") == "9823" );
    REQUIRE( Tokenizer::oper("(#$1193") == "1193" );
}
