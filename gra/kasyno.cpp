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

bool Kasyno::czyKoniecGry() {
    for (int i = 0; i < liczbaGraczy; i++) {
        if (!gracze[i].czySpasowal()) {
            return false;
        }
    }
    return true;
}

void Kasyno::graj() {
    tasuj();

    liczbaGraczy = pobierzLiczbeGraczy();
    gracze = new Gracz[liczbaGraczy];

    for (int i = 0; i < liczbaGraczy; i++) {
        gracze[i].ustawKasyno(this);
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
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
    }

    zakonczGre();
}

void Kasyno::zakonczGre() {
    for (int i = 0; i < liczbaGraczy; i++) {
        std::cout << "\nKarty gracza " << i + 1 << "\n";
        gracze[i].wyswietlKarty();
    }
}
