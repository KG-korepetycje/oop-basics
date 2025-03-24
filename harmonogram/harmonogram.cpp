#include "harmonogram.h"

Harmonogram::Harmonogram(){
    liczbaCzasow = 0;
    rozmiar = 0;
    zestawienie = nullptr;
}

int Harmonogram::pobierzLiczbeCzasow() {
    return liczbaCzasow;
}

void Harmonogram::dodajCzas(Czas& _czas) {
    if (liczbaCzasow == rozmiar) {
        if (zestawienie == nullptr) {
            rozmiar = 1;
            zestawienie = new Czas[rozmiar];
        } else {
            Czas *noweZestawienie = new Czas[rozmiar * 2];

            for (int i = 0; i < rozmiar; i++) {
                noweZestawienie[i] = zestawienie[i];
            }
            rozmiar = rozmiar * 2;

            delete[] zestawienie;
            zestawienie = noweZestawienie;
        }
    }
    zestawienie[liczbaCzasow] = _czas;
    liczbaCzasow++;
}

Czas& Harmonogram::pobierzCzas(int indeks) {
    return zestawienie[indeks];
}

void Harmonogram::wypiszZestawienie() {
    for (int i = 0; i < liczbaCzasow; i++) {
        std::cout << "Czas nr " << (i + 1) << ":\n";
        zestawienie[i].wyswietl();
        std::cout << "\n";
    }
}
