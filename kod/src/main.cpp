#include <iostream>
#include <string>
#include <firma.hpp>
#include <config.hpp>
#include <gra.hpp>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    Firma firma;
    Gra gra(firma);
    string komenda;
    double stan_gry = START_VALUE;
    double wartosc_spolki = 0;
    double ile = 0;
    int ile_rat = 0;
    int i;

    cout<<setprecision(2)<<fixed;
    cout<<"Witaj w nowej grze, stan początkowy to: "<<stan_gry<<" zl, milej zabawy!"<<endl;
    while(true){

        cout<<endl<<"Wpisz polecenie do wykonania: "<<endl;
        cin>>komenda;


        if(komenda == "kt"){    //koniec tury

            stan_gry = gra.tura();      
            wartosc_spolki = gra.wartosc_spolki();      

            if(wartosc_spolki >= MAX_VALUE){
                cout<<"\n\n\tWygrales! Gratulacje!\n\tKoniec gry\n"<<endl;
                return 0;
            }
            else if(stan_gry < 0){
                cout<<"\n\n\tUUU Przegrales... :(((\n\tMozesz probowac od nowa\n"<<endl;
                return 0;
            }
            cout<<endl<<"Aktualny stan twojej gry: "<<stan_gry<<" zl"<<endl;

        }
        else if(komenda == "kred"){     //wzięcie kredytu

            cout<<"Podaj ile kredytu chcesz zaciagnac oraz na jaki okres czasu (w miesiacach/turach): "<<endl;
            cin>>ile>>ile_rat;

            if(ile_rat <= MAX_CZAS && ile <= MAX_DLUG*gra.wartosc_spolki()){
                gra.chce_kredyt(ile, ile_rat);
            }
            else{
                cout<<"Nie mozemy udzielic ci takiego kredytu"<<endl;
            }
            
        }
        else{             // pozostałe akcje do zagrania
            i = gra.akcja_gracza(komenda); 
            if(i == 1){
                cout<<"Nie jest to poprawna komenda"<<endl;
            }
        }
        komenda = "";
    }

    return 0;
}