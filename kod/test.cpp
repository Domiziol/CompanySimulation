#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "firma.hpp"

TEST_CASE("Testy dla firmy", "[firma]") {
    Firma f;

    SECTION("Sprawdz stan konta") {
        REQUIRE(f.rozlicz_miesiac() == 42.0);
    }

    SECTION("Sprawdz wartosc spolki") {
        REQUIRE(f.jaka_wartosc_spolki() == 0.0);
    }
    
    SECTION("Sprawdz wartosc spolki") {
        REQUIRE(f.stan_kredytow() == 0.0);
    }

}