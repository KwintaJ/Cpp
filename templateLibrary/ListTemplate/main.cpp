#include <iostream>

#include "list.h"
#include "osoba.h"

using namespace std;

int main()
{
    List<int> liczby;
    
    int element;
    while(cin >> element)
    {
        liczby.push_back(element);
    }

    cout << endl << "W kolejnosci:" << endl;
    for(List<int>::iterator it = liczby.begin(); it != liczby.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << endl << "Na odwrot:" << endl;
    for(List<int>::reverse_iterator it = liczby.reverse_begin(); it != liczby.reverse_end(); ++it)
    {
        cout << *it << endl;
    }
}