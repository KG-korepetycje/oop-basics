#include <iostream>
#include <fstream>
#include <limits>

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

    while (true) {
        std::cout << "\nPodaj liczbe graczy [1-3]: ";
        std::cin >> liczbaGraczy;

        if (std::cin.fail() == true) {
            std::cout << "\nBledna wartosc! Prosze podac wartosc liczbowa z zakresu 1-3.\n";  // opcjonalne
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (liczbaGraczy >= 1 && liczbaGraczy <= 3)
                return liczbaGraczy;
            else
                std::cout << "\nLiczba graczy musi być z zakresu 1-3.\n";
        }
    }
}

int Kasyno::pobierzLiczbeBotow() {
    int liczbaBotow = -1;

    while (true) {
        std::cout << "\nPodaj liczbe botow [1-3]: ";
        std::cin >> liczbaBotow;

        if (std::cin.fail() == true) {
            std::cout << "\nBledna wartosc! Prosze podac wartosc liczbowa z zakresu 1-3.\n";  // opcjonalne
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (liczbaBotow >= 1 && liczbaBotow <= 3)
                return liczbaBotow;
            else
                std::cout << "\nLiczba botow musi byc z zakresu 1-3.\n";
        }
    }
}

std::string Kasyno::pobierzNazweGracza(int _numerGracza) {
    std::string nazwa;

    while (true) {
        std::cout << "\nPodaj nazwe gracza nr " << _numerGracza << " (3-20 znakow): ";
        std::cin >> nazwa;

        if (std::cin.fail() == true) {
            std::cout << "\nBledna wartosc! Prosze podac poprawna nazwe gracza.\n";  // opcjonalne
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (nazwa.length() >= 3 && nazwa.length() <= 20)
                return nazwa;
            else
                std::cout << "\nNazwa musi byc napisem o dlugosci od 3 do 20 znakow.\n";
        }
    }
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

    while (true) {
        std::cout << "\nCzy rozpoczac nowa gre?\n";
        std::cout << "[1] tak\n";
        std::cout << "[2] nie\n";
        std::cout << "Wybor: ";
        std::cin >> decyzja;

        if (std::cin.fail() == true) {
            std::cout << "\nBledna wartosc! Prosze podac wartosc liczbowa 1 lub 2.\n";  // opcjonalne
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (decyzja == 1 || decyzja == 2)
                return decyzja == 1;
            else
                std::cout << "\nDecyzja musi byc rowna 1 lub 2.\n";
        }
    }
}

void Kasyno::graj() {
    tasuj();

    liczbaGraczy = pobierzLiczbeGraczy();
    gracze = new Gracz[liczbaGraczy];

    liczbaBotow = pobierzLiczbeBotow();
    boty = new Bot[liczbaBotow];

    for (int i = 0; i < liczbaGraczy; i++) {
        std::string nazwa = pobierzNazweGracza(i + 1);
        gracze[i].ustawNazwe(nazwa);
        gracze[i].ustawKasyno(this);
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
    }

    Strategia strategie[] = {ZACHOWAWCZA, NORMALNA, RYZYKUJACA};
    for (int i = 0; i < liczbaBotow; i++) {
        // std::string nazwa = "Bot" + ('A' + i);
        std::string nazwa = "BotA";
        boty[i].ustawNazwe(nazwa);
        boty[i].ustawKasyno(this);
        boty[i].ustawStrategie(strategie[rand() % 3]);  // Losowy indeks 0-2
        boty[i].wezKarte(dajKarte());
        boty[i].wezKarte(dajKarte());
    }

    while(!czyKoniecGry()) { // sprawdzamy, czy wszyscy spasowali
        for (int i = 0; i < liczbaGraczy; i++) {
            if (!gracze[i].czySpasowal()) {
                std::cout << "\nKarty gracza [" << gracze[i].pobierzNazwe() << "]\n";
                gracze[i].wyswietlKarty();
                gracze[i].czyPasuje();
            } else {
                std::cout << "\nGracz [" << gracze[i].pobierzNazwe() << "] SPASOWAL!\n";
            }
        }
        for (int i = 0; i < liczbaBotow; i++) {
            if (!boty[i].czySpasowal())
                boty[i].czyPasuje();
            else
                std::cout << "\nBot [" << boty[i].pobierzNazwe() << "] SPASOWAL!\n";
        }
    }

    zakonczGre();
    if (czyKolejnaGra()) {
        delete[] gracze;
        delete[] boty;
        graj();
    }
}

void Kasyno::eksportRaportu() {
    std::ofstream raport;
    raport.open("./raport_gry.txt", std::ofstream::out);
    raport << "NAZWA GRACZA" << " LICZBA PUNKTOW" << "STATUS";
    for (int i = 0; i < liczbaGraczy; i++) {
        raport << gracze[i].pobierzNazwe() << " " << gracze[i].wezWartoscKart() << " " << gracze[i].pobierzStatus() << "\n";
    }
    raport.close();
}

void Kasyno::zakonczGre() {
    for (int i = 0; i < liczbaGraczy; i++) {
        std::cout << "\nKarty gracza [" << gracze[i].pobierzNazwe() << "]\n";
        gracze[i].wyswietlKarty();
    }
    for (int i = 0; i < liczbaBotow; i++) {
        std::cout << "\nKarty bota [" << boty[i].pobierzNazwe() << "]\n";
        boty[i].wyswietlKarty();
    }

    // Warunek nr 1
    bool czyJestZwyciezca = false;
    for (int i = 0; i < liczbaGraczy; i++) {
        if (gracze[i].wezWartoscKart() == 21) {
            std::cout << "\nGracz [" << gracze[i].pobierzNazwe() << "] WYGRAL!\n";
            gracze[i].ustawStatus("Wygrany");
            czyJestZwyciezca = true;
        }
    }
    for (int i = 0; i < liczbaBotow; i++) {
        if (boty[i].wezWartoscKart() == 21) {
            std::cout << "\nBot [" << boty[i].pobierzNazwe() << "] WYGRAL!\n";
            boty[i].ustawStatus("Wygrany");
            czyJestZwyciezca = true;
        }
    }
    if (czyJestZwyciezca)
        return;

    // Warunek nr 2
    int maksDozwolonyWynik = -1;
    std::string nazwa;
    bool czyGracz;
    for (int i = 0; i < liczbaGraczy; i++) {
        if (gracze[i].wezWartoscKart() < 21 && gracze[i].wezWartoscKart() > maksDozwolonyWynik) {
            maksDozwolonyWynik = gracze[i].wezWartoscKart();
            nazwa = gracze[i].pobierzNazwe();
            czyGracz = true;
        }
    }
    for (int i = 0; i < liczbaBotow; i++) {
        if (boty[i].wezWartoscKart() < 21 && boty[i].wezWartoscKart() > maksDozwolonyWynik) {
            maksDozwolonyWynik = boty[i].wezWartoscKart();
            nazwa = boty[i].pobierzNazwe();
            czyGracz = false;
        }
    }
    if (maksDozwolonyWynik != -1) {
        if (czyGracz)
            std::cout << "\nGracz [" << nazwa << "] WYGRAL!\n";
        else
            std::cout << "\nBot [" << nazwa << "] WYGRAL!\n";
    } else {
        // Warunek nr 3
       std::cout << "\nWSZYSCY PRZEGRALI!\n";
    }

    eksportRaportu();
}
