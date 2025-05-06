#ifndef FIRMA
#define FIRMA

#include <memory>
#include <variant>
#include <vector>
#include <list>
#include <kredyt.hpp>
#include <pracownik.hpp>

using namespace std;

using v_prac = variant<Inz, Mag, Mkt, Rob>;

class Firma{
    double stan_konta;
    list< double > historia_dochodow;
    list< Kredyt > kredyty;
    int n_prac[4] = {0, 0, 0, 0};   //tablica służąca to trzymania liczby każdego rodzaju pracowników
    vector< v_prac > prac;                  // - kolejność jak w variancie
    double zaplac_wynagrodzenia();
    double splacaj_kredyty();
    double oblicz_przychod();
    

    public:
    Firma();
    void drukuj_pracownikow();
    void zatrudnij(const v_prac& pracownik);
    double rozlicz_miesiac(); 
    double jaka_wartosc_spolki();
    void wez_kredyt(const Kredyt& kred);
    
};

#endif