#ifndef GRA
#define GRA

#include <memory>
#include <firma.hpp>
#include <config.hpp>

using namespace std;

class Gra{
    unique_ptr<Firma> firma;

    public:
    Gra(Firma& fir);
    int akcja_gracza(string komenda);
    double tura();      //rozegranie i podsumowanie jednego miesiąca; zwraca stan konta firmy
    double wartosc_spolki();    //zwraca wartość spółki
    void chce_kredyt(double ile, int ile_rat);
};

#endif