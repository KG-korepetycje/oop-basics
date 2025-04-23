#pragma once
#include <iostream>

#include "gracz.h"
#include "karta.h"


class Kasyno {
    private:
        Karta talia[52];
        bool wydaneKarty[52];

        Gracz gracze[3];

    public:
        Kasyno();

        Karta* dajKarte();

        void tasuj();
        void graj();
};
