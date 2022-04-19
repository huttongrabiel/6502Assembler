#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "16 Bit Little Endian Least Significant Byte Extraction" ) {
    Translate translate;

    REQUIRE( translate.oper_low_byte("8347") == 47 );
    REQUIRE( translate.oper_low_byte("7263") == 63 );
    REQUIRE( translate.oper_low_byte("38") == 0 );
    REQUIRE( translate.oper_low_byte("98") == 0 );
}
