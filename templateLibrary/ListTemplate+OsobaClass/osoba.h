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

#ifndef OSOBA
#define OSOBA

class Osoba
{
    public:
        /* constructors */
        explicit Osoba(std::string, int);
        Osoba() = default;

        /* setters, getters */
        void setImie(std::string);
        void setWiek(int);
        std::string getImie() const;
        int getWiek() const;
        
        /* methods */
        void edit();
        std::ostream &print(std::ostream&) const;
        std::istream &read(std::istream&);
        bool operator<(const Osoba&);

    private:
        std::string imie{""};
        int wiek{0};
};

#endif
