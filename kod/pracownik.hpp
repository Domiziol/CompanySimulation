#ifndef PRACOWNIK
#define PRACOWNIK

#include <string>
#include <config.hpp>
using namespace std;

class Pracownik{
    protected:
    string imie;
    double wynagrodzenie = -1;

    public:
    Pracownik() = default;
    Pracownik(string im);
    const double get_wyn() const;
    const void print() const;
};


class Inz : public Pracownik{
    string wydzial;
    static const double CI;

    public:
    Inz(string im, string wyd);
    static const double get_C();
};


class Mag : public Pracownik{
    bool obsl_widl;
    static const double CMag;

    public:
    Mag(string im, bool czy_widl);
    static const double get_C();
};


class Mkt : public Pracownik{
    int follows;
    static const double CMkt;

    public:
    Mkt(string im, int fol);
    static const double get_C();
};


class Rob : public Pracownik{
    double but;
    static const double CR;

    public:
    Rob(string im, double bu);
    static const double get_C();
};

#endif