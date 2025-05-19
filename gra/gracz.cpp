#include <iostream>
#include <limits>

#include "gracz.h"
#include "kasyno.h"

void Gracz::ustawKasyno(Kasyno* _kasyno) {
    kasyno = _kasyno;
}

void Gracz::ustawNazwe(const std::string& _nazwa) {
    nazwa = _nazwa;
}

std::string& Gracz::pobierzNazwe() {
    return nazwa;
}

void Gracz::ustawStatus(const std::string& _status) {
    status = _status;
}

std::string& Gracz::pobierzStatus() {
    return status;
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

    while (true) {
        std::cout << "\nPasujesz czy grasz dalej?\n";
        std::cout << "[1] pasuje\n";
        std::cout << "[2] gram dalej\n";
        std::cout << "Wybor: ";
        std::cin >> decyzja;

        if (std::cin.fail() == true) {
            std::cout << "\nBledna wartosc! Prosze podac wartosc liczbowa 1 lub 2.\n";  // opcjonalne
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (decyzja == 1 || decyzja == 2)
                break;
            else
                std::cout << "\nDecyzja musi byc rowna 1 lub 2.\n";
        }
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

int Gracz::wezWartoscKart() {
    return wartoscKart;
}
