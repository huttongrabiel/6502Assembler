#include <catch2/catch_test_macros.hpp>
#include <Translate.h>

TEST_CASE( "Return Address/Oper as a Hexadecimal Integer" ) {
    TranslationHelpers translationHelpers;

    REQUIRE( translationHelpers.address_as_int("60") == 96);
    REQUIRE( translationHelpers.address_as_int("37") == 55);
    REQUIRE( translationHelpers.address_as_int("10") == 16);
    REQUIRE( translationHelpers.address_as_int("FF") == 255);
    REQUIRE( translationHelpers.address_as_int("9") == 9);
}
