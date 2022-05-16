#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( " Instruction is branch instruction or not " ) {
    REQUIRE( TranslationHelpers::is_branch_instruction("BPL") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BMI") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BVC") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BVS") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BCC") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BCS") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BNE") == true );
    REQUIRE( TranslationHelpers::is_branch_instruction("BEQ") == true );

    REQUIRE( TranslationHelpers::is_branch_instruction("INX") == false );
    REQUIRE( TranslationHelpers::is_branch_instruction("BRK") == false );
    REQUIRE( TranslationHelpers::is_branch_instruction("STA #$54, X") == false );
}
