#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "Convert Decimal Value to Binary String Equivalent" ) {
    TranslationHelpers translationHelpers;

    REQUIRE( translationHelpers.decimal_to_binary(2) == "00000010" );
    REQUIRE( translationHelpers.decimal_to_binary(128) == "10000000" );
    REQUIRE( translationHelpers.decimal_to_binary(94) == "01011110" );
}
