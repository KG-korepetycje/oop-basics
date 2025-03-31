#include "harmonogram.h"

Harmonogram::Harmonogram() {
    liczbaCzasow = 0;
    rozmiar = 0;
    zestawienie = nullptr;
}

Harmonogram::Harmonogram(const Harmonogram& _inny) {
    liczbaCzasow = _inny.liczbaCzasow;
    rozmiar = _inny.rozmiar;
    zestawienie = new Czas[rozmiar];  // Alokujemy swoja pamiec
    for (int i = 0; i < liczbaCzasow; i++) {
        zestawienie[i] = _inny.zestawienie[i];  // Kopia Czasu
    }
}

Harmonogram::~Harmonogram() {
    delete[] zestawienie;
}

int Harmonogram::pobierzLiczbeCzasow() {
    return liczbaCzasow;
}

void Harmonogram::dodajCzas(const Czas& _czas) {
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

void Harmonogram::dodajCzas(int sek, int min, int godz) {
    if (liczbaCzasow == rozmiar) {
        if (zestawienie == nullptr) {
            rozmiar = 1;
            zestawienie = new Czas[rozmiar];
        } else {
            Czas *noweZestawienie = new Czas[rozmiar * 2];  // Zwiekszenie o pewna wartosc

            for (int i = 0; i < rozmiar; i++) {
                noweZestawienie[i] = zestawienie[i];
            }
            rozmiar = rozmiar * 2;

            delete[] zestawienie;
            zestawienie = noweZestawienie;
        }
    }
    Czas czas(sek, min, godz);
    zestawienie[liczbaCzasow] = czas;
    liczbaCzasow++;
}

Czas& Harmonogram::pobierzCzas(int indeks) {
    if (indeks < 0 || indeks >= liczbaCzasow) {
        throw std::out_of_range("Niepoprawny indeks!");

        // Jesli nie wyjatek to przykladowo mozna tak to obsluzyc
        // std::cout << "Niepoprawny indeks!\n";
        // Czas nieistniejacyCzas(0,0,0);
        // return nieistniejacyCzas;
    }
    return zestawienie[indeks];
}

Czas& Harmonogram::operator[](int indeks) {
    return pobierzCzas(indeks);
}

Harmonogram& Harmonogram::operator=(const Harmonogram& _inny) {
    if (&_inny == this)  // Jesli adres innego (&_inny) jest rowne adresowi obecnego (this)
        return *this;  // to zwracamy referencje na obecny (czyli *this)

    delete[] zestawienie;
    liczbaCzasow = _inny.liczbaCzasow;
    rozmiar = _inny.rozmiar;
    zestawienie = new Czas[rozmiar];  // Alokujemy swoja pamiec
    for (int i = 0; i < liczbaCzasow; i++) {
        zestawienie[i] = _inny.zestawienie[i];  // Kopia Czasu
    }

    return *this;
}

// Harmonogram Harmonogram::kopiaDoZakresu(Czas& zakres) {
//     Harmonogram kopiaH;
//     Czas sumaKopiiH;

//     for (int i = 0; i < liczbaCzasow; i++) {
//         if ((sumaKopiiH + zestawienie[i]) <= zakres) {
//             kopiaH.dodajCzas(zestawienie[i]);
//             sumaKopiiH += zestawienie[i];
//         } else {
//             return kopiaH;
//         }
//     }

//     return kopiaH;
// }

Harmonogram Harmonogram::kopiaDoZakresu(Czas& zakres) {
    Harmonogram kopiaH;

    for (int i = 0; i < liczbaCzasow; i++) {
        if ((kopiaH.sumaZestawienia() + zestawienie[i]) <= zakres) {  // Mniej wydajny - za kazdym razem przechodzimy od nowa po zestawieniu
            kopiaH.dodajCzas(zestawienie[i]);
        } else {
            return kopiaH;
        }
    }

    return kopiaH;
}

Harmonogram Harmonogram::kopiaPowyzejZakresu(Czas& zakres) {
    Harmonogram kopiaH;

    for (int i = 0; i < liczbaCzasow; i++) {
        if (zestawienie[i] > zakres) {
            kopiaH.dodajCzas(zestawienie[i]);
        }
    }

    return kopiaH;
}

Czas Harmonogram::sumaZestawienia() {
    Czas suma;
    for (int i = 0; i < liczbaCzasow; i++) {
        suma += zestawienie[i];
    }
    return suma;
}

void Harmonogram::wypiszZestawienie() {
    std::cout << "Harmonogram (liczba czasow: " << liczbaCzasow << ")\n";
    std::cout << "-------------------------------\n";
    for (int i = 0; i < liczbaCzasow; i++) {
        std::cout << i + 1 << ".";
        zestawienie[i].wyswietl();
    }
    std::cout << "\n\n";
}
