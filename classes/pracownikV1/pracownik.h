#include <string.h>
#include "osoba.h"

#ifndef PRACOWNIK
#define PRACOWNIK

class Pracownik
{
    public:
        /* constructors */
        explicit Pracownik(std::string, int, int);
        Pracownik() = default;

        /* setters, getters */
        void setZarobki(int);
        int getZarobki() const;

        /* methods */
        std::ostream &print(std::ostream&) const;
        std::istream &read(std::istream&);

    private:
        Osoba ktos;
        int zarobki{0};
};

#endif
