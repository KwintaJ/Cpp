//############################################//
//                                            //
//    Jan Kwinta                17.05.2022    //
//                                            //
//    Projekt: C++ templatka listy            //
//                                            //
//    main.cpp                                //
//                                            //
//############################################//

#include <iostream>
#include <utility>
#include <algorithm>

#include "list.h"

using namespace std;

int main()
{
    List<int> liczby;
    
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
}
