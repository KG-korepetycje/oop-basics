#include <iostream>
#include "harmonogram.h"


int main() {
    Harmonogram harmonogram;

    Czas czas1, czas2;
    czas1.ustawCzas(9, 14, 1);
    czas2.ustawCzas(15, 10, 5);

    harmonogram.dodajCzas(czas1);
    harmonogram.dodajCzas(czas2);
    harmonogram.wypiszZestawienie();

    Czas& czas = harmonogram.pobierzCzas(0);
    czas.ustawCzas(8, 8, 8);
    harmonogram[1].ustawCzas(8, 4, 2);
    // harmonogram.pobierzCzas(5).ustawCzas(9, 9, 9);  // Indeks poza zakresem

    harmonogram.wypiszZestawienie();

    Czas czas3(0, 0, 3);
    Czas czas4(0, 30, 1);
    Czas czas5(60, 14, 0);
    harmonogram.dodajCzas(czas3);
    harmonogram.dodajCzas(czas4);
    harmonogram.dodajCzas(czas5);

    harmonogram.wypiszZestawienie();
    Czas czas6 = harmonogram[3];
    harmonogram.dodajCzas(czas6);
    harmonogram.wypiszZestawienie();
    Czas sumaZestawienia = harmonogram.sumaZestawienia();
    std::cout << "Suma zestawienia: ";
    sumaZestawienia.wyswietl();
    std::cout << "\n";
    return 0;
}
