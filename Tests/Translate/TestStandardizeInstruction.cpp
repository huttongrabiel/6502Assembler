#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "Standardize Instruction" ) {
    REQUIRE( Translate::standardize_instruction({"LDA", "$4321", "X"}) == "LDA $XXXX X" );
}
