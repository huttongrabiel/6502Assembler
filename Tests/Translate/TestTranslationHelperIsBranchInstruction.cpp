#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( " Instruction is branch instruction or not " ) {
    TranslationHelpers translationHelpers;

    REQUIRE( translationHelpers.is_branch_instruction("BPL") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BMI") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BVC") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BVS") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BCC") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BCS") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BNE") == true );
    REQUIRE( translationHelpers.is_branch_instruction("BEQ") == true );

    REQUIRE( translationHelpers.is_branch_instruction("INX") == false );
    REQUIRE( translationHelpers.is_branch_instruction("BRK") == false );
    REQUIRE( translationHelpers.is_branch_instruction("STA #$54, X") == false );
}
