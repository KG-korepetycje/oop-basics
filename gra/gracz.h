#pragma once
#include <iostream>

#include "karta.h"

class Kasyno;

class Gracz {
    private:
        Karta* karty[10];
        int liczbaKart = 0;
        int wartoscKart = 0;

        Kasyno* kasyno;
        bool spasowal = false;

    public:
        void ustawKasyno(Kasyno* _kasyno);

        void wezKarte(Karta* _karta);
        void wyswietlKarty();

        bool czyPasuje();
        bool czySpasowal();
};
