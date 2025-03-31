#include <iostream>
#include "czas.h"

#pragma once

class Harmonogram {

    private:
        int liczbaCzasow;
        int rozmiar;
        Czas *zestawienie;

    public:
        Harmonogram();
        Harmonogram(const Harmonogram& _inny);  // Zasada trzech (1)
        ~Harmonogram();  // Zasada trzech (2)

        int pobierzLiczbeCzasow();

        void dodajCzas(const Czas& _czas);  // Moze byc const, bo nie modyfikujemy otrzymanego czasu w tej funkcji
        void dodajCzas(int sek, int min = 0, int godz = 0);
        Czas& pobierzCzas(int indeks);

        Czas& operator[](int indeks);
        Harmonogram& operator=(const Harmonogram& _inny);  // Zasada trzech (3)

        Harmonogram kopiaDoZakresu(Czas& zakres);
        Harmonogram kopiaPowyzejZakresu(Czas& zakres);
        
        Czas sumaZestawienia();

        void wypiszZestawienie();

};
