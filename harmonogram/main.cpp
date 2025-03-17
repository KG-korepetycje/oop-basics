#include <iostream>

class Czas {

    private:
        int godziny;
        int minuty;
        int sekundy;

        void ustawGodziny(int nowaWartosc);
        void ustawMinuty(int nowaWartosc);
        void ustawSekundy(int nowaWartosc);

    public:
        int pobierzGodziny();
        int pobierzMinuty();
        int pobierzSekundy();

        void ustawCzas(int sek, int min, int godz);
        void ustawCzas(int sek, int min);
        void ustawCzas(int sek);
        // void ustawCzas(int sek, int min = 0, int godz = 0);

        Czas operator+(Czas& _czas);
        bool operator<(Czas& _czas);

        void wyswietl();
};

int Czas::pobierzGodziny() {
    return godziny;
}

int Czas::pobierzMinuty() {
    return minuty;
}

int Czas::pobierzSekundy() {
    return sekundy;
}

void Czas::ustawGodziny(int nowaWartosc) {
    godziny = nowaWartosc;
}

void Czas::ustawMinuty(int nowaWartosc) {
    if (nowaWartosc < 0) {
        minuty = 0;
    }
    else if (nowaWartosc > 59) {
        godziny = godziny + nowaWartosc / 60;
        minuty = nowaWartosc % 60;
    }
    else {
        minuty = nowaWartosc;
    }
}

void Czas::ustawSekundy(int nowaWartosc) {
    if (nowaWartosc < 0) {
        sekundy = 0;
    }
    else if (nowaWartosc > 59) {
        minuty = minuty + nowaWartosc / 60;
        sekundy = nowaWartosc % 60;
        ustawMinuty(minuty);
    }
    else {
        sekundy = nowaWartosc;
    }
}

void Czas::ustawCzas(int sekundy, int minuty, int godziny) {
    ustawGodziny(godziny);
    ustawMinuty(minuty);
    ustawSekundy(sekundy);
}

void Czas::ustawCzas(int sekundy, int minuty) {
    ustawGodziny(0);
    ustawMinuty(minuty);
    ustawSekundy(sekundy);
}

void Czas::ustawCzas(int sekundy) {
    ustawGodziny(0);
    ustawMinuty(0);
    ustawSekundy(sekundy);
}
// void Czas::ustawCzas(int sekundy, int minuty = 0, int godziny = 0) {
//     ustawGodziny(godziny);
//     ustawMinuty(minuty);
//     ustawSekundy(sekundy);
// }

Czas Czas::operator+(Czas& _czas) {
   Czas wynik;

   int suma_sekund = sekundy + _czas.sekundy;
   int suma_minut = minuty + _czas.minuty;
   int suma_godzin = godziny + _czas.godziny;
   wynik.ustawCzas(suma_sekund, suma_minut, suma_godzin);

   return wynik;
}

bool Czas::operator<(Czas& _czas) {
    if (godziny != _czas.godziny) {
        if (godziny < _czas.godziny)
            return true;
        else
            return false;
    }
    // Godziny rowne, czyli sprawdzamy minuty
    if (minuty != _czas.minuty) {
        if (minuty < _czas.minuty)
            return true;
        else
            return false;
    }
    // Godziny i minuty rowne, czyli sprawdzamy sekundy
    if (sekundy < _czas.sekundy)
        return true;
    return false;
}

void Czas::wyswietl() {
    std::cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << "\n";
}

int main() {
    // Czas czas1;
    // Czas czas2;

    // // czas1.ustawCzas(23, 40, 37);
    // czas1.ustawCzas(9, 14, 1);
    // czas2.ustawCzas(50, 26, 3);

    // Czas czas3 = czas1 + czas2;
    // czas3.wyswietl();

    Czas czas1;
    Czas czas2;

    czas1.ustawCzas(9, 14, 1);
    czas2.ustawCzas(9, 14, 1);

    std::cout << "czas1 < czas2: " << (czas1 < czas2) << std::endl;
    return 0;
}
