//############################################//
//                                            //
//    Jan Kwinta                17.05.2022    //
//                                            //
//    Projekt: C++ templatka listy            //
//                                            //
//    main.cpp                                //
//                                            //
//############################################//

#include <algorithm>
#include <iostream>
#include <fstream>

#include "list.h"
#include "osoba.h"

using namespace std;

int main()
{
    /* List<int> liczby;
    
    int element;
    while(cin >> element)
    {
        liczby.push_back(element);
    }

    liczby.sort();

    cout << endl << "Mniejsze - wieksze:" << endl;
    for(List<int>::iterator it = liczby.begin(); it != liczby.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << endl << "Wieksze - mniejsze:" << endl;
    for(List<int>::reverse_iterator it = liczby.reverse_begin(); it != liczby.reverse_end(); ++it)
    {
        cout << *it << endl;
    }
    */

    List<Osoba> grupa;

    ifstream fin;    
    fin.open("./osoby.txt");
    if(!fin.good())
    {
        cerr << "ERROR brak pliku osoby.txt\n";
        exit(1);
    }

    Osoba genericPerson;
    while(genericPerson.read(fin))
        grupa.push_back(genericPerson);    

    fin.close();

    grupa.sort();

    for(List<Osoba>::iterator it = grupa.begin(); it != grupa.end(); ++it)
    {
        it->print(cout);
    }
}