#include <catch2/catch_test_macros.hpp>
#include <SymbolTable.h>

TEST_CASE( "Check if Instruction Is Label" ) {
    REQUIRE( SymbolTable::is_label("LOOP") == false );
    REQUIRE( SymbolTable::is_label("LOOP:") == true );
    REQUIRE( SymbolTable::is_label("BNE") == false );
    REQUIRE( SymbolTable::is_label("LDA #$4853, X") == false );
    REQUIRE( SymbolTable::is_label("WHILE:") == true );
}
