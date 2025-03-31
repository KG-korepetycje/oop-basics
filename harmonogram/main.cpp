#include <iostream>
#include "harmonogram.h"


void testZasadyTrzech() {
    Harmonogram h1;
    h1.dodajCzas(0, 5);
    h1.dodajCzas(0, 10);
    h1.dodajCzas(0, 15);
    h1.dodajCzas(0, 20);
    h1.dodajCzas(0, 30);

    Harmonogram h2(h1);
    Harmonogram h3;
    h3 = h1;

    h1.wypiszZestawienie();
    h2.wypiszZestawienie();
    h3.wypiszZestawienie();
}

void testKopiiDoZakresu() {
    Harmonogram h1;
    h1.dodajCzas(0, 5);
    h1.dodajCzas(0, 10);
    h1.dodajCzas(0, 15);
    h1.dodajCzas(0, 20);
    h1.dodajCzas(0, 30);

    std::cout << "Harmonogram h1:\n";
    h1.wypiszZestawienie();
    
    Czas zakres(0, 25);
    Harmonogram kopiaDoZakresu = h1.kopiaDoZakresu(zakres);
    std::cout << "Kopia do zakresu:\n";
    kopiaDoZakresu.wypiszZestawienie();
}

void testKopiiPowyzejZakresu() {
    Harmonogram h1;
    h1.dodajCzas(0, 5);
    h1.dodajCzas(0, 10);
    h1.dodajCzas(0, 15);
    h1.dodajCzas(0, 20);
    h1.dodajCzas(0, 30);

    std::cout << "Harmonogram h1:\n";
    h1.wypiszZestawienie();
    
    Czas zakres(0, 12);
    Harmonogram kopiaPowyzejZakresu = h1.kopiaPowyzejZakresu(zakres);
    std::cout << "Kopia powyzej zakresu:\n";
    kopiaPowyzejZakresu.wypiszZestawienie();
}


int main() {
    // Harmonogram harmonogram;

    // // Czas czas1, czas2;
    // // czas1.ustawCzas(9, 14, 1);
    // // czas2.ustawCzas(15, 10, 5);

    // harmonogram.dodajCzas(9, 14, 1);
    // harmonogram.dodajCzas(15, 10, 5);
    // harmonogram.wypiszZestawienie();

    // Czas& czas = harmonogram.pobierzCzas(0);
    // czas.ustawCzas(8, 8, 8);
    // harmonogram[1].ustawCzas(8, 4, 2);
    // // harmonogram.pobierzCzas(5).ustawCzas(9, 9, 9);  // Indeks poza zakresem

    // harmonogram.wypiszZestawienie();

    // // Czas czas3(0, 0, 3);
    // // Czas czas4(0, 30, 1);
    // // Czas czas5(60, 14, 0);
    // harmonogram.dodajCzas(10800);
    // harmonogram.dodajCzas(0, 30, 1);
    // harmonogram.dodajCzas(60, 14, 0);

    // harmonogram.wypiszZestawienie();
    // Czas czas6 = harmonogram[3];
    // harmonogram.dodajCzas(czas6.pobierzSekundy(), czas6.pobierzMinuty(), czas6.pobierzGodziny());
    // harmonogram.wypiszZestawienie();
    // Czas sumaZestawienia = harmonogram.sumaZestawienia();
    // std::cout << "Suma zestawienia: ";
    // sumaZestawienia.wyswietl();
    // std::cout << "\n";


    // testZasadyTrzech();
    // testKopiiDoZakresu();
    testKopiiPowyzejZakresu();
    return 0;
}
