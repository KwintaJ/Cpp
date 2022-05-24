//############################################//
//                                            //
//    Jan Kwinta                17.05.2022    //
//                                            //
//    Projekt: C++ templatka listy            //
//    z uzyciem klasy Osoba                   //
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
