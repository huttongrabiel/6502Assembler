#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( " Instruction is branch instruction or not " ) {
    REQUIRE( Translate::is_branch_instruction("BPL") == true );
    REQUIRE( Translate::is_branch_instruction("BMI") == true );
    REQUIRE( Translate::is_branch_instruction("BVC") == true );
    REQUIRE( Translate::is_branch_instruction("BVS") == true );
    REQUIRE( Translate::is_branch_instruction("BCC") == true );
    REQUIRE( Translate::is_branch_instruction("BCS") == true );
    REQUIRE( Translate::is_branch_instruction("BNE") == true );
    REQUIRE( Translate::is_branch_instruction("BEQ") == true );

    REQUIRE( Translate::is_branch_instruction("INX") == false );
    REQUIRE( Translate::is_branch_instruction("BRK") == false );
    REQUIRE( Translate::is_branch_instruction("STA #$54, X") == false );
}
