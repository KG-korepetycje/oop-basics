#pragma once
#include <iostream>

#include "bot.h"
#include "gracz.h"
#include "karta.h"


class Kasyno {
    private:
        Karta talia[52];
        bool wydaneKarty[52];

        Gracz* gracze;
        int liczbaGraczy;

        Bot* boty;
        int liczbaBotow;

        int pobierzLiczbeGraczy();
        int pobierzLiczbeBotow();
        bool czyKoniecGry();
        bool czyKolejnaGra();

    public:
        Kasyno();
        ~Kasyno();

        Karta* dajKarte();

        void tasuj();
        void graj();
        void zakonczGre();
};
