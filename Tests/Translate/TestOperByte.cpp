#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "Test Oper High Byte Extraction" ) {
    REQUIRE( Translate::oper_byte("8347", Translate::OperByte::High) == 131 );
    REQUIRE( Translate::oper_byte("7263", Translate::OperByte::High) == 114 );
    REQUIRE( Translate::oper_byte("38", Translate::OperByte::High) == 56 );
    REQUIRE( Translate::oper_byte("98", Translate::OperByte::High) == 152 );
}

TEST_CASE( "Test Oper Low Byte Extraction" ) {
    REQUIRE( Translate::oper_byte("8347", Translate::OperByte::Low) == 71 );
    REQUIRE( Translate::oper_byte("7263", Translate::OperByte::Low) == 99 );
    REQUIRE( Translate::oper_byte("38", Translate::OperByte::Low) == -1 );
    REQUIRE( Translate::oper_byte("98", Translate::OperByte::Low) == -1 );
}