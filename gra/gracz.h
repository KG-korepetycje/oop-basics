#pragma once
#include <iostream>

#include "karta.h"

class Kasyno;

class Gracz {
    protected:
        Karta* karty[10];
        int liczbaKart = 0;
        int wartoscKart = 0;

        Kasyno* kasyno;
        bool spasowal = false;

        std::string nazwa;
        std::string status = "Przegrany";

    public:
        void ustawKasyno(Kasyno* _kasyno);
        void ustawNazwe(const std::string& _nazwa);
        std::string& pobierzNazwe();
        void ustawStatus(const std::string& _status);
        std::string& pobierzStatus();

        void wezKarte(Karta* _karta);
        void wyswietlKarty();

        bool czyPasuje();
        bool czySpasowal();

        int wezWartoscKart();
};
