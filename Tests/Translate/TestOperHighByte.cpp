#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( " 16 Bit Little Endian Most Significant Byte Extraction" ) {
    Translate translate;

    REQUIRE( translate.oper_high_byte("8347") == 131 );
    REQUIRE( translate.oper_high_byte("7263") == 114 );
    REQUIRE( translate.oper_high_byte("38") == 56 );
    REQUIRE( translate.oper_high_byte("98") == 152 );
}
