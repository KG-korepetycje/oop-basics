#include <iostream>

class Czas
{
    private:
        int godziny;

    public:
        int pobierzGodziny();
        bool ustawGodziny(int nowaWartosc);
        void wyswietl();
    
};


int Czas::pobierzGodziny() {
    return godziny;
}



bool Czas::ustawGodziny(int nowaWartosc) {
    if (nowaWartosc >= 0 && nowaWartosc <= 23) {
        godziny = nowaWartosc;
        return true;
    }
    return false;
}


void Czas::wyswietl() {
    std::cout << "Czas: " << godziny << "\n";
}


// Czas& zainicjujCzas() {
//     Czas nowyCzas;

//     nowyCzas.ustawGodziny(5);

//     return nowyCzas;
// }


Czas& zainicjujCzasDobry(Czas& czas) {
    czas.ustawGodziny(5);

    return czas;
}


void zainicjujCzasReferencja(Czas& czas) {
    czas.ustawGodziny(5);
}

int main() {
    // Czas czas1;
    // Czas& czas2 = zainicjujCzasDobry(czas1);
    // czas2.wyswietl();
    Czas czas;
    zainicjujCzasReferencja(czas);
    czas.wyswietl();

    return 0;
}