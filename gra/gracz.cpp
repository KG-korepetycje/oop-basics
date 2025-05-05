#include "gracz.h"

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

bool Gracz::czySpasowal() {
    return spasowal;
}
