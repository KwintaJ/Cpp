//############################################//
//                                            //
//    Jan Kwinta                17.05.2022    //
//                                            //
//    Projekt: C++ klasa osoba                //
//                                            //
//    osoba.h                                 //
//                                            //
//############################################//

#include <string>
#include <iostream>
#include <istream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#ifndef OSOBA
#define OSOBA

class Osoba
{
public:
    /* constructors */
    explicit Osoba(string i, int w): imie{i}, wiek{w}
    {
    }
    Osoba() = default;

    /* setters, getters */
    void setImie(string n)
    {
        imie=n;
    } 
    void setWiek(int a)
    {
        wiek=a;
    }
    string getImie() const
    {
        return imie;
    }
    int getWiek() const
    {
        return wiek;
    }
       
    /* methods */
    void edit()
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

    ostream &print(ostream& sout) const
    {
        sout << left << setw(12) << imie << right << setw(6) << wiek << endl;
        return sout;
    }

    istream &read(istream& sin)
    {
        sin >> imie >> wiek;
        return sin;
    }

    bool operator<(const Osoba &B)
    {
        if(imie == B.getImie())
            return wiek < B.getWiek();
        return imie < B.getImie();
    }

private:
    string imie{""};
    int wiek{0};
};

#endif
