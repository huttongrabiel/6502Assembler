#include <catch2/catch_test_macros.hpp>
#include <Tokenizer.h>

TEST_CASE( "Oper (ie 4843) of the instruction" ) {
    Tokenizer tokenizer;

    REQUIRE( tokenizer.oper("#$8473") == "8473" );
    REQUIRE( tokenizer.oper("$2218") == "2218" );
    REQUIRE( tokenizer.oper("$2810") == "2810" );
    REQUIRE( tokenizer.oper("$28") == "28" );
    REQUIRE( tokenizer.oper("($9823") == "9823" );
    REQUIRE( tokenizer.oper("(#$1193") == "1193" );
}
