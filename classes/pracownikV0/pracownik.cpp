#include <string>
#include <iostream>
#include <istream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "pracownik.h"

using namespace std;

/* non-default constructors */
Pracownik::Pracownik(string i, int w, int z): imie{i}, wiek{w}, zarobki{z} {}

/* setters, getters */
void Pracownik::setImie(string n)
{
    imie = n;
} 
void Pracownik::setWiek(int a)
{
    wiek = a;
}
void Pracownik::setZarobki(int w)
{
    zarobki = w;
}
string Pracownik::getImie() const
{
    return imie;
}
int Pracownik::getWiek() const
{
    return wiek;
}
int Pracownik::getZarobki() const
{
    return zarobki;
}
   
/* methods */
ostream &Pracownik::print(ostream& sout) const
{
    sout << left << setw(12) << imie << right << setw(6) << wiek << right << setw(12) << zarobki << endl;
    return sout;
}

istream &Pracownik::read(istream& sin)
{
    sin >> imie >> wiek >> zarobki;
    return sin;
}

