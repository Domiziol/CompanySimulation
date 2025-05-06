#include <memory>
#include <iostream>
#include <randomy.hpp>
#include <gra.hpp>
#include <kredyt.hpp>

Gra::Gra(Firma& fir){
    firma = make_unique<Firma>(fir);
}

int Gra::akcja_gracza(string komenda){
    if(komenda == "lp"){
        firma->drukuj_pracownikow();
    }
    else if(komenda == "zinz"){
        string imie = get_random_name();
        string wydzial = get_random_faculty();
        firma->zatrudnij(Inz(imie, wydzial)); 
    }
    else if(komenda == "zmag"){
        string imie = get_random_name();
        bool czy = get_random_widlowy();
        firma->zatrudnij(Mag(imie, czy)); 
    }
    else if(komenda == "zmkt"){
        string imie = get_random_name();
        int fol = get_random_follows();
        firma->zatrudnij(Mkt(imie, fol)); 
    }
    else if(komenda == "zrob"){
        string imie = get_random_name();
        double but = get_random_size();
        firma->zatrudnij(Rob(imie, but)); 
    }
    else{
        return 1;
    }
    return 0;
}


double Gra::tura(){
    return firma->rozlicz_miesiac();
}

double Gra::wartosc_spolki(){
    return firma->jaka_wartosc_spolki();
}

void Gra::chce_kredyt(double ile, int ile_rat){
    firma->wez_kredyt(Kredyt(ile, ile_rat));
}
