#include <string>

#ifndef PRACOWNIK
#define PRACOWNIK

class Pracownik
{
    public:
        /* constructors */
        explicit Pracownik(std::string, int, int);
        Pracownik() = default;

        /* setters, getters */
        void setImie(std::string);
        void setWiek(int);
        void setZarobki(int);
        std::string getImie() const;
        int getWiek() const;
        int getZarobki() const;
        
        /* methods */
        void edit();
        std::ostream &print(std::ostream&) const;
        std::istream &read(std::istream&);

    private:
        std::string imie{""};
        int wiek{0};
        int zarobki{0};
};

#endif
