#include <string>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <iomanip>

#include "pracownik.h"
#include "osoba.h"

using namespace std;

/* non-default constructors */
Pracownik::Pracownik(string n, int a, int w):ktos{n, a}, zarobki{w} {}

/* setters, getters */
void Pracownik::setZarobki(int w)
{
	zarobki = w;
}
int Pracownik::getZarobki() const
{
	return zarobki;
}

/* methods */
ostream &Pracownik::print(ostream& sout) const
{
    sout << left << setw(12) << ktos.getImie() << right << setw(6) << ktos.getWiek() << right << setw(12) << zarobki << endl;
    return sout;
}

istream &Pracownik::read(istream& sin)
{
    ktos.read(sin);
    sin >> zarobki;
    return sin;
}

