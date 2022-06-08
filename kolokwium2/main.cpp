//############################################//
//                                            //
//    Jan Kwinta                24.05.2022    //
//                                            //
//    Projekt: C++ templatka vectora          //
//                                            //
//    main.cpp                                //
//                                            //
//############################################//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "vector.h"
#include "pracownik.h"

using namespace std;

bool operator<(const Pracownik &A, const Pracownik &B)
{
    if(A.getImie() == B.getImie())
    {
        if(A.getWiek() == B.getWiek())
            return A.getZarobki() < B.getZarobki();
        return A.getWiek() < B.getWiek();
    }
    return A.getImie() < B.getImie();
}

int main()
{
    Vector<Pracownik> grupa;
    
    /* wczytanie do wektora z pliku */
    cout << endl << "0. Wczytanie pracownikow z pliku \"pracownicy.txt\" do wektora" << endl << endl;
    ifstream fin;    
    fin.open("./pracownicy.txt");
    if(!fin.good())
    {
        cerr << "ERROR brak pliku.txt\n";
        exit(1);
    }

    Pracownik genericPracownik;
    while(genericPracownik.read(fin))
        grupa.push_back(genericPracownik);
        
    /* 1. */
    cout << "1. Wypisanie wektora pracownikow na ekran" << endl << endl;
    int i = 0;
    for(Vector<Pracownik>::iterator it = grupa.begin(); it != grupa.end(); it++)
    {
        cout << left << setw(4) << i << "    ";
        (*it).print(cout);
        i++;
    }
    cout << endl << endl;
    
    /* 2. */
    cout << "2. Wypisanie wektora pracownikow w odwrotnej kolejnosci" << endl << endl;
    i = 0;
    for(Vector<Pracownik>::reverse_iterator it = grupa.rbegin(); it != grupa.rend(); it++)
    {
        cout << left << setw(4) << i << "    ";
        (*it).print(cout);
        i++;
    }
    cout << endl << endl;
    
    /* 3. */
    cout << "3. Posortowanie wektora pracownikow i wypisanie" << endl << endl;
    sort(grupa.begin(), grupa.end());
    i = 0;
    for(Vector<Pracownik>::iterator it = grupa.begin(); it != grupa.end(); it++)
    {
        cout << left << setw(4) << i << "    ";
        (*it).print(cout);
        i++;
    }
    cout << endl << endl;
    
    int pozycjaInt;
    
    /* 4. */
    cout << "4. Dodanie elementu" << endl << endl;
    string nI;
    int nW, nZ;

    cout << "Wpisz imie nowego pracownika: ";
    cin >> nI;
    
    cout << "Wpisz wiek nowego pracownika: ";
    cin >> nW;
    
    cout << "Wpisz zarobki nowego pracownika: ";
    cin >> nZ;
    
    Pracownik nowyPracownik{nI, nW, nZ};
    
    cout << "Numer pozycji, na ktory chcesz dodac nowego pracownika: ";
    cin >> pozycjaInt;
    
    if(pozycjaInt > grupa.size()  || pozycjaInt < 0)
    {
        cout << "    Niepoprawny numer pozycji" << endl;
    }
    else
    {
        Vector<Pracownik>::iterator pozycjaIterator = grupa.begin();
        for(int j = 0; j < pozycjaInt; j++)
            pozycjaIterator++;
            
        grupa.insert(pozycjaIterator, nowyPracownik);
        
        cout << endl << "Wektor pracownikow po zmianach" << endl << endl;
        i = 0;
        for(Vector<Pracownik>::iterator it = grupa.begin(); it != grupa.end(); it++)
        {   
            cout << left << setw(4) << i << "    ";
            (*it).print(cout);
            i++;
        }
        cout << endl << endl;
    }
    
    /* 5. */
    cout << "5. Usuniecie elementu" << endl << endl;
    
    cout << "Numer pozycji, z ktorej chcesz usunac pracownika: ";
    cin >> pozycjaInt;
    
    if(pozycjaInt > grupa.size() || pozycjaInt < 0)
    {
        cout << "    Niepoprawny numer pozycji" << endl;
    }
    else
    {
        Vector<Pracownik>::iterator pozycjaIterator = grupa.begin();
        for(int j = 0; j < pozycjaInt; j++)
            pozycjaIterator++;
            
        grupa.erase(pozycjaIterator);
        
        cout << endl << "Wektor pracownikow po zmianach" << endl << endl;
        i = 0;
        for(Vector<Pracownik>::iterator it = grupa.begin(); it != grupa.end(); it++)
        {   
            cout << left << setw(4) << i << "    ";
            (*it).print(cout);
            i++;
        }
        cout << endl << endl;
    }
    
    return 0;
}
