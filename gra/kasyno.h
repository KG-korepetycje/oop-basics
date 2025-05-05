#pragma once
#include <iostream>

#include "gracz.h"
#include "karta.h"


class Kasyno {
    private:
        Karta talia[52];
        bool wydaneKarty[52];

        Gracz* gracze;
        int liczbaGraczy;

        int pobierzLiczbeGraczy();

    public:
        Kasyno();
        ~Kasyno();

        Karta* dajKarte();

        void tasuj();
        void graj();
};
