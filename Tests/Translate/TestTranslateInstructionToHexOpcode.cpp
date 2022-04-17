#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

Translate translate;

TEST_CASE( "Translate Instruction to Its OpCode in Hex" ) {
    REQUIRE( translate.translate_instruction_to_hex_opcode("LDA $XX X") == 0xB5 );
    REQUIRE( translate.translate_instruction_to_hex_opcode("INX") == 0xE8 );
}
