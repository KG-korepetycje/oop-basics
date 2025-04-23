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

    for (int i = 0; i < 3; i++) {
        gracze[i] = Gracz();
    }
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

void Kasyno::graj() {
    tasuj();

    for (int i = 0; i < 3; i++) {
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
        std::cout << "\nKarty gracza " << i + 1 << "\n";
        gracze[i].wyswietlKarty();
    }
}
