#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( " 16 Bit Little Endian Most Significant Byte Extraction" ) {
    Translate translate;

    REQUIRE( translate.oper_high_byte("8347") == 83 );
    REQUIRE( translate.oper_high_byte("7263") == 72 );
    REQUIRE( translate.oper_high_byte("38") == 38 );
    REQUIRE( translate.oper_high_byte("98") == 98 );
}
