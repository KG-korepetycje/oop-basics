#include "czas.h"


int Czas::pobierzGodziny()
{
    return godziny;
}


int Czas::pobierzMinuty()
{
    return minuty;
}


int Czas::pobierzSekundy()
{
    return sekundy;
}


bool Czas::ustawGodziny(int nowaWartosc)
{
    if (nowaWartosc >= 0 && nowaWartosc <= 23) {
        godziny = nowaWartosc;
        return true;
    }
    return false;
}


bool Czas::ustawMinuty(int nowaWartosc)
{
    if (nowaWartosc >= 0 && nowaWartosc <= 59) {
        minuty = nowaWartosc;
        return true;
    }
    return false;
}


bool Czas::ustawSekundy(int nowaWartosc)
{
    if (nowaWartosc >= 0 && nowaWartosc <= 59) {
        sekundy = nowaWartosc;
        return true;
    }
    return false;
}


void Czas::wyswietl()
{
    std::cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << "\n";
}
