#pragma once
#include <iostream>

#include "karta.h"


class Gracz {
    private:
        Karta* karty[10];
        int liczbaKart = 0;
        int wartoscKart = 0;

    public:
        
        void wezKarte(Karta* _karta);
        void wyswietlKarty();
};
