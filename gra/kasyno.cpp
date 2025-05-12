#include <iostream>

#include "kasyno.h"

Kasyno::Kasyno() {
    int licznik = 0;
    for (int kolor = 0; kolor < 4; kolor++) {
        for (int wartosc = 0; wartosc < 13; wartosc++) {
            talia[licznik] = Karta(kolor, wartosc);
            wydaneKarty[licznik] = false;
            licznik++;
        }
    }
}

Kasyno::~Kasyno() {
    delete[] gracze;
    delete[] boty;
}

Karta* Kasyno::dajKarte() {
    for (int i = 0; i < 52; i++) {
        // if (wydaneKarty[i] == false)
        if (!wydaneKarty[i]) {
            wydaneKarty[i] = true;
            return &talia[i];
        }
    }
    return nullptr;  // Gdy nie ma wolnych kart
}

void Kasyno::tasuj() {
    for (int i = 0; i < 100; i++) {
        int indeks_1 = rand() % 52;
        int indeks_2 = rand() % 52;

        Karta tempKarta = talia[indeks_1];
        talia[indeks_1] = talia[indeks_2];
        talia[indeks_2] = tempKarta;

        bool tempFlaga = wydaneKarty[indeks_1];
        wydaneKarty[indeks_1] = wydaneKarty[indeks_2];
        wydaneKarty[indeks_2] = tempFlaga;
    }
}

int Kasyno::pobierzLiczbeGraczy() {
    int liczbaGraczy = -1;

    while (liczbaGraczy < 0 || liczbaGraczy > 3) {
        std::cout << "Podaj liczbe graczy [1-3]: ";
        std::cin >> liczbaGraczy;
    }

    return liczbaGraczy;
}

int Kasyno::pobierzLiczbeBotow() {
    int liczbaBotow = -1;

    while (liczbaBotow < 0 || liczbaBotow > 3) {
        std::cout << "Podaj liczbe botow [1-3]: ";
        std::cin >> liczbaBotow;
    }

    return liczbaBotow;
}

bool Kasyno::czyKoniecGry() {
    for (int i = 0; i < liczbaGraczy; i++) {
        if (!gracze[i].czySpasowal()) {
            return false;
        }
    }
    for (int i = 0; i < liczbaBotow; i++) {
        if (!boty[i].czySpasowal()) {
            return false;
        }
    }
    return true;
}

bool Kasyno::czyKolejnaGra() {
    int decyzja = -1;

    while (decyzja < 1 || decyzja > 2) {
        std::cout << "\nCzy rozpoczac nowa gre?\n";
        std::cout << "[1] tak\n";
        std::cout << "[2] nie\n";

        std::cout << "Wybor: ";
        std::cin >> decyzja;
    }

    if (decyzja == 1)
        return true;
    return false;
}

void Kasyno::graj() {
    tasuj();

    liczbaGraczy = pobierzLiczbeGraczy();
    gracze = new Gracz[liczbaGraczy];

    liczbaBotow = pobierzLiczbeBotow();
    boty = new Bot[liczbaBotow];

    for (int i = 0; i < liczbaGraczy; i++) {
        gracze[i].ustawKasyno(this);
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
    }

    Strategia strategie[] = {ZACHOWAWCZA, NORMALNA, RYZYKUJACA};
    for (int i = 0; i < liczbaBotow; i++) {
        boty[i].ustawKasyno(this);
        boty[i].ustawStrategie(strategie[rand() % 3]);  // Losowy indeks 0-2
        boty[i].wezKarte(dajKarte());
        boty[i].wezKarte(dajKarte());
    }

    while(!czyKoniecGry()) { // sprawdzamy, czy wszyscy spasowali
        for (int i = 0; i < liczbaGraczy; i++) {
            if (!gracze[i].czySpasowal()) {
                std::cout << "\nKarty gracza " << i + 1 << "\n";
                gracze[i].wyswietlKarty();
                gracze[i].czyPasuje();
            } else {
                std::cout << "\nGracz " << i + 1 << " SPASOWAL!\n";
            }
        }
        for (int i = 0; i < liczbaBotow; i++) {
            if (!boty[i].czySpasowal())
                boty[i].czyPasuje();
            else
                std::cout << "\nBot " << i + 1 << " SPASOWAL!\n";
        }
    }

    zakonczGre();
    if (czyKolejnaGra()) {
        delete[] gracze;
        delete[] boty;
        graj();
    }
}

void Kasyno::zakonczGre() {
    for (int i = 0; i < liczbaGraczy; i++) {
        std::cout << "\nKarty gracza " << i + 1 << "\n";
        gracze[i].wyswietlKarty();
    }
    for (int i = 0; i < liczbaBotow; i++) {
        std::cout << "\nKarty bota " << i + 1 << "\n";
        boty[i].wyswietlKarty();
    }

    // Warunek nr 1
    bool czyJestZwyciezca = false;
    for (int i = 0; i < liczbaGraczy; i++) {
        if (gracze[i].wezWartoscKart() == 21) {
            std::cout << "\nGracz " << i + 1 << " WYGRAL!\n";
            czyJestZwyciezca = true;
        }
    }
    for (int i = 0; i < liczbaBotow; i++) {
        if (boty[i].wezWartoscKart() == 21) {
            std::cout << "\nBot " << i + 1 << " WYGRAL!\n";
            czyJestZwyciezca = true;
        }
    }
    if (czyJestZwyciezca)
        return;

    // Warunek nr 2
    int maksDozwolonyWynik = -1;
    int indeks = 0;
    bool czyGracz;
    for (int i = 0; i < liczbaGraczy; i++) {
        if (gracze[i].wezWartoscKart() < 21 && gracze[i].wezWartoscKart() > maksDozwolonyWynik) {
            maksDozwolonyWynik = gracze[i].wezWartoscKart();
            indeks = i + 1;
            czyGracz = true;
        }
    }
    for (int i = 0; i < liczbaBotow; i++) {
        if (boty[i].wezWartoscKart() < 21 && boty[i].wezWartoscKart() > maksDozwolonyWynik) {
            maksDozwolonyWynik = boty[i].wezWartoscKart();
            indeks = i + 1;
            czyGracz = false;
        }
    }
    if (maksDozwolonyWynik != -1) {
        if (czyGracz)
            std::cout << "\nGracz " << indeks << " WYGRAL!\n";
        else
            std::cout << "\nBot " << indeks << " WYGRAL!\n";
    } else {
        // Warunek nr 3
       std::cout << "\nWSZYSCY PRZEGRALI!\n";
    }
}
