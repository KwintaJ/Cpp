// klasa Pracownik ma pole typu Osoba

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "pracownik.h"

using namespace std;

void wczytajPlik(vector<Pracownik> &A)
{
	Pracownik zwyklyPracownik;

    ifstream fin;    
    fin.open("./pracownicy.txt");
    if(!fin.good())
    {
        cerr << "ERROR\n";
        exit(1);
    }

    while(zwyklyPracownik.read(fin))
        A.push_back(zwyklyPracownik);    

    fin.close();
}

void wypiszPracownikow(vector<Pracownik> &A, ostream &sout)
{
	sout << "      BAZA DANYCH:" << endl << endl;
    sout << "Lp    " << left << setw(12) << "Imie" << right << setw(6) << "Wiek" << right << setw(12) << "Zarobki" << endl;
    sout << "____________________________________" << endl;
    int Lp = 1;
    for(vector<Pracownik>::iterator it = A.begin(); it != A.end(); it++)
    {   
        sout << Lp++ << ":    ";
        it->print(sout);
    }
}

int main()
{
	vector<Pracownik> firma;
	wczytajPlik(firma);
	wypiszPracownikow(firma, cout);
}
