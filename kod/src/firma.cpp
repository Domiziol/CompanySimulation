#include <variant>
#include <vector>
#include <iostream>
#include <firma.hpp>
#include <config.hpp>
#include <memory>

using namespace std;

Firma::Firma(){
    
    zatrudnij(Inz("Adam", "MEIL"));
    zatrudnij(Mag("Piotr", true));
    zatrudnij(Mkt("Eryk", 350));
    zatrudnij(Rob("Jurek", 41.5));
    stan_konta = START_VALUE;
}


void Firma::zatrudnij(const v_prac& pracownik){
    
    prac.push_back(pracownik);
    ++n_prac[pracownik.index()];
}


void Firma::wez_kredyt(const Kredyt& kred){
    stan_konta += kred.get_wartosc();
    kredyty.push_back(kred);
}


void Firma::drukuj_pracownikow(){

    for(auto pracownik : prac){
        visit([](const auto& p){
            p.print();
        }, pracownik);
    }
}


double Firma::zaplac_wynagrodzenia(){
   
    double wynag = 0;
    for(auto pracownik : prac){
        visit([&wynag](const auto& p){ 
            wynag += p.get_wyn(); 
        }, pracownik);
    }
    return wynag;
}


double Firma::oblicz_przychod(){
   
    double pojemnosc = n_prac[1] * Mag::get_C();    //indeks 1 - magazynier
    double cena = n_prac[0] * Inz::get_C();         //indeks 0 - inżynier
    double popyt = n_prac[2] * Mkt::get_C();        //indeks 2 - marketer
    double teo_prod = n_prac[3] * Rob::get_C();     //indeks 3 - robotnik

    double fakt_prod = min(pojemnosc, teo_prod);
    double sprzedane = min(popyt, fakt_prod);
    double przychod = sprzedane * cena;
    return przychod;
}

double Firma::splacaj_kredyty(){
    
    double sum_raty = 0;
    double rata = 0;
    for(auto it = kredyty.begin(); it!=kredyty.end(); ++it){
        rata = (*it).splac_rate();

        if(rata == 0){      //oznacza ze kredyt juz został spłacony i może być usunięty
            it = kredyty.erase(it);
        }
        else sum_raty += rata;
    }
    return sum_raty;
}


double Firma::rozlicz_miesiac(){
    
    double dochod = oblicz_przychod() - zaplac_wynagrodzenia() - splacaj_kredyty();
    if(historia_dochodow.size() >= N){      //utrzymanie aktualnych dochodów
        historia_dochodow.pop_front();
    }

    historia_dochodow.push_back(dochod);
    stan_konta += dochod;
    return stan_konta;      //stan po przeliczeniu miesiąca
}


double Firma::jaka_wartosc_spolki(){
                        //wartością spółki jest średnia z N miesięcy dochodów(!), 
    double sum = 0;            // - nie samych przychodów
    for(auto it = historia_dochodow.begin(); it != historia_dochodow.end(); ++it)
    {
        sum += (*it);
    }
    return sum/N;       
}
