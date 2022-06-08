#include <string>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <iomanip>

#include "pracownik.h"
#include "osoba.h"

using namespace std;

/* non-default constructors */
Pracownik::Pracownik(string i, int w, int z):Osoba{i, w}, zarobki{z} {}

/* setters, getters */
void Pracownik::setZarobki(int z)
{
    zarobki = z;
}
int Pracownik::getZarobki() const
{
    return zarobki;
}

/* methods */
ostream &Pracownik::print(ostream& sout) const
{
    sout << left << setw(12) << getImie() << right << setw(6) << getWiek() << right << setw(12) << zarobki << endl;
    return sout;
}

istream &Pracownik::read(istream& sin)
{   
    Osoba::read(sin);
    sin >> zarobki;
    return sin;
}

