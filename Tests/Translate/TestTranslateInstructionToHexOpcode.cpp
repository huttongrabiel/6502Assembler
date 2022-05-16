#include <catch2/catch_test_macros.hpp>
#include <Translate.h>
#include <SymbolTable.h>

TEST_CASE( "Translate Instruction to Its OpCode in Hex" ) {
    Translate translate;

    // Second parameter is just a placeholder in testing. It is the program counter typically
    REQUIRE( translate.translate_instruction_to_hex_opcode("LDA $XX X", 0) == 0xB5 );
    REQUIRE( translate.translate_instruction_to_hex_opcode("INX", 0) == 0xE8 );
}
