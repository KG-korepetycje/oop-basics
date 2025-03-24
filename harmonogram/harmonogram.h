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

        int pobierzLiczbeCzasow();

        void dodajCzas(Czas& _czas);
        Czas& pobierzCzas(int indeks);

        void wypiszZestawienie();

};
