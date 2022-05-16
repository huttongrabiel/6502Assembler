#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "Convert Decimal Value to Binary String Equivalent" ) {
    REQUIRE( TranslationHelpers::decimal_to_binary(2) == "00000010" );
    REQUIRE( TranslationHelpers::decimal_to_binary(128) == "10000000" );
    REQUIRE( TranslationHelpers::decimal_to_binary(94) == "01011110" );
}
