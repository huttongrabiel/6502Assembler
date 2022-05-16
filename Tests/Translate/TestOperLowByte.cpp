#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "16 Bit Little Endian Least Significant Byte Extraction" ) {
    REQUIRE( Translate::oper_low_byte("8347") == 71 );
    REQUIRE( Translate::oper_low_byte("7263") == 99 );
    REQUIRE( Translate::oper_low_byte("38") == 0 );
    REQUIRE( Translate::oper_low_byte("98") == 0 );
}
