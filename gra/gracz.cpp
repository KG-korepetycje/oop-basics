#include <iostream>

#include "gracz.h"
#include "kasyno.h"

void Gracz::ustawKasyno(Kasyno* _kasyno) {
    kasyno = _kasyno;
}

void Gracz::wezKarte(Karta* _karta) {
    if (liczbaKart >= 0 && liczbaKart < 10){
        karty[liczbaKart] = _karta;
        liczbaKart++;
        wartoscKart += _karta->getWartosc();
    }
    // else - czy potrzebny?
}

void Gracz::wyswietlKarty() {
    for (int i = 0; i < liczbaKart; i++) {
        karty[i]->wypisz();
        std::cout << std::endl;
    }
    std::cout << "Suma wartosci kart: " << wartoscKart << "\n";
}

bool Gracz::czyPasuje() {
    int decyzja = -1;

    while (decyzja < 1 || decyzja > 2) {
        std::cout << "\nPasujesz czy grasz dalej?\n";
        std::cout << "[1] pasuje\n";
        std::cout << "[2] gram dalej\n";

        std::cout << "Wybor: ";
        std::cin >> decyzja;
    }

    if (decyzja == 1) {
        spasowal = true;
        return true;
    }

    wezKarte(kasyno->dajKarte());
    if (wartoscKart >= 21) {
        spasowal = true;
    }

    return false;
}

bool Gracz::czySpasowal() {
    return spasowal;
}
