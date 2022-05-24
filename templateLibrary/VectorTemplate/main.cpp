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

#include "vector.h"

using namespace std;

int main()
{
    Vector<int> liczby;
    for(int i = 0; i < 10; i++)
    {
        int e;
        cin >> e;
        liczby.push_back(e); 
    }
    
    sort(liczby.begin(), liczby.end());
    
    for(auto x : liczby)
        cout << x << endl;
}
