#include <kredyt.hpp>
#include <cmath>

using namespace std;

Kredyt::Kredyt(double ile, int ile_rat){
    dlug = (ile/ile_rat + 2*log(ile_rat)) * ile_rat;      //caly dlug: kredyt razem z odsetkami
    wartosc = ile;
    pojedyncza_rata = ile/ile_rat + log(ile_rat);       //do pojedynczej raty wychodzacej z dlugu
}                                                         // i rozlozenia na ileś miesięcy dodana jest
                                                          // wartość odsetek - log(ile_rat) 
double Kredyt::splac_rate(){

    if(dlug > pojedyncza_rata){
        dlug -= pojedyncza_rata;
        return pojedyncza_rata;
    }
    else return 0;
}

double const Kredyt::get_wartosc() const {
    return wartosc;
}
