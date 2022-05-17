#include <string>
#include <iostream>
#include <istream>
#include <iomanip>
#include <cstdlib>

#include "osoba.h"

using namespace std;

/* non-default constructors */
Osoba::Osoba(string i, int w): imie{i}, wiek{w} {}

/* setters, getters */
void Osoba::setImie(string n)
{
    imie=n;
} 
void Osoba::setWiek(int a)
{
    wiek=a;
}
string Osoba::getImie() const
{
    return imie;
}
int Osoba::getWiek() const
{
    return wiek;
}
   
/* methods */
void Osoba::edit()
{
    cout << "Wprowadz nowe imie dla " << imie << ": ";
    string noweImie;
    getline(cin, noweImie);
    if(!noweImie.empty())
        this->imie = noweImie;
    cout << "Wprowadz nowy wiek dla " << imie <<" (" << wiek << "): ";
    string nowyWiek;
    getline(cin, nowyWiek);
    if(!nowyWiek.empty())
        this->wiek = stoi(nowyWiek);
}

ostream &Osoba::print(ostream& sout) const
{
    sout << left << setw(12) << imie << right << setw(6) << wiek << endl;
    return sout;
}

istream &Osoba::read(istream& sin)
{
    sin >> imie >> wiek;
    return sin;
}

bool Osoba::operator<(const Osoba &B)
{
    if(imie == B.getImie())
        return wiek < B.getWiek();
    return imie < B.getImie();
}
