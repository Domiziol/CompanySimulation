#ifndef KREDYT
#define KREDYT

#include <config.hpp>

class Kredyt{
    double dlug;
    double wartosc;
    double pojedyncza_rata;

    public:
    Kredyt(double ile, int ile_rat);
    double splac_rate();
    double const get_wartosc() const;

};


#endif