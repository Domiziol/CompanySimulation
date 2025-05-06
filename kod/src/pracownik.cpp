#include <string>
#include <iostream>
#include <pracownik.hpp>
#include <config.hpp>

using namespace std;

Pracownik::Pracownik(string im) : imie(im) {};
Inz::Inz(string im, string wyd) : Pracownik(im), wydzial(wyd) { wynagrodzenie = WynInzyniera; };
Mag::Mag(string im, bool czy_widl) : Pracownik(im), obsl_widl(czy_widl) { wynagrodzenie = WynMagazyniera; };
Mkt::Mkt(string im, int fol) : Pracownik(im), follows(fol) { wynagrodzenie = WynMarketera; };
Rob::Rob(string im, double bu) : Pracownik(im), but(bu) { wynagrodzenie = WynRobotnika; };


const double Inz::CI = WspInzynier;
const double Mag::CMag = WspMagazynier;
const double Mkt::CMkt = WspMarketer;
const double Rob::CR = WspRobotnik;

//getter współczynników
const double Inz::get_C(){
    return CI;
}
const double Mag::get_C(){
    return CMag;
}
const double Mkt::get_C(){
    return CMkt;
}
const double Rob::get_C(){
    return CR;
}

//getter wynagrodzenia
const double Pracownik::get_wyn() const {
    return wynagrodzenie;
}

//printer (imie i wynagrodzenie)
const void Pracownik::print() const { cout<<"Jestem "<<imie<<", zarabiam "<<wynagrodzenie<<" zl brutto"<<endl; }



