//############################################//
//                                            //
//    Jan Kwinta                24.05.2022    //
//                                            //
//    Projekt: C++ templatka vectora          //
//                 korzystajaca z klasy Osoba //
//                                            //
//    main.cpp                                //
//                                            //
//############################################//

#include <algorithm>
#include <iostream>
#include <fstream>

#include "osoba.h"
#include "vector.h"

using namespace std;

int main()
{
    Vector<Osoba> grupa;
    
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
    
    sort(grupa.begin(), grupa.end());
    
    for(const auto &x : grupa)
        x.print(cout);
}
