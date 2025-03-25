#include "harmonogram.h"

Harmonogram::Harmonogram() {
    liczbaCzasow = 0;
    rozmiar = 0;
    zestawienie = nullptr;
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

Czas& Harmonogram::pobierzCzas(int indeks) {
    if (indeks < 0 || indeks >= liczbaCzasow) {
        throw std::out_of_range("Niepoprawny indeks!");

        // Jesli nie wyjatek to przykladowo mozna tak to obsluzyc
        // std::cout << "Niepoprawny indeks!\n";
        // static Czas nieistniejacyCzas;
        // return nieistniejacyCzas;
    }
    return zestawienie[indeks];
}

Czas& Harmonogram::operator[](int indeks) {
    return pobierzCzas(indeks);
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
