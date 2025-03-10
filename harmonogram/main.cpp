#include <iostream>

#include "czas.h"


int main()
{
    Czas czas1, czas2;

    // Poprawne wartosci
    czas1.ustawGodziny(7);
    czas1.ustawMinuty(46);
    czas1.ustawSekundy(13);

    czas2.ustawGodziny(17);
    czas2.ustawMinuty(19);
    czas2.ustawSekundy(39);

    std::cout << "czas1:\n";
    czas1.wyswietl();

    std::cout << "\nczas2:\n";
    czas2.wyswietl();

    // Niepoprawne wartosci
    bool status;
    status = czas1.ustawGodziny(-2);
    std::cout << "\nStatus ustawienia godziny -> -2: " << status;

    status = czas1.ustawMinuty(83);
    std::cout << "\nStatus ustawienia minut -> 83: " << status;

    status = czas1.ustawSekundy(5);
    std::cout << "\nStatus ustawienia sekund -> 5: " << status;

    std::cout << "\nczas1:\n";
    czas1.wyswietl();

    status = czas1.ustawGodziny(24);
    std::cout << "\nStatus ustawienia godziny -> 24: " << status;

    status = czas1.ustawMinuty(197246);
    std::cout << "\nStatus ustawienia minut -> 197246: " << status;

    status = czas1.ustawSekundy(61);
    std::cout << "\nStatus ustawienia sekund -> 61: " << status;

    std::cout << "\nczas1:\n";
    czas1.wyswietl();

    return 0;
}
