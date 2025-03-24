#include "czas.h"

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

void Czas::operator+=(Czas& _czas) {
    int suma_sekund = sekundy + _czas.sekundy;
    int suma_minut = minuty + _czas.minuty;
    int suma_godzin = godziny + _czas.godziny;
    ustawCzas(suma_sekund, suma_minut, suma_godzin);
}

bool Czas::operator==(Czas& _czas) {
    if (godziny == _czas.godziny && minuty == _czas.minuty && sekundy == _czas.sekundy)
        return true;
    return false;
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

bool Czas::operator<=(Czas& _czas) {
    if (operator<(_czas) || operator==(_czas))
        return true;
    return false;
}

bool Czas::operator>(Czas& _czas) {
    if (!operator<=(_czas))
        return true;
    return false;
}

bool Czas::operator>=(Czas& _czas) {
    if (!operator<(_czas))
        return true;
    return false;
}

bool Czas::operator!=(Czas& _czas) {
    if (!operator==(_czas))
        return true;
    return false;
}

void Czas::wyswietl() {
    std::cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << "\n";
}
