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
        ~Harmonogram();

        int pobierzLiczbeCzasow();

        void dodajCzas(const Czas& _czas);  // Moze byc const, bo nie modyfikujemy otrzymanego czasu w tej funkcji
        Czas& pobierzCzas(int indeks);
        Czas& operator[](int indeks);
        
        Czas sumaZestawienia();

        void wypiszZestawienie();

};
