#include <catch2/catch_test_macros.hpp>
#include <SymbolTable.h>

TEST_CASE( "Check if Instruction Is Label" ) {
    SymbolTable symbolTable;
    REQUIRE( symbolTable.is_label("LOOP") == false );
    REQUIRE( symbolTable.is_label("LOOP:") == true );
    REQUIRE( symbolTable.is_label("BNE") == false );
    REQUIRE( symbolTable.is_label("LDA #$4853, X") == false );
    REQUIRE( symbolTable.is_label("WHILE:") == true );
}
