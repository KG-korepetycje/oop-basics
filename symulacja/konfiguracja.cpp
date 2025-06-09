#include "konfiguracja.h"
#include "wyjatki.h"

Konfiguracja::Konfiguracja(const std::string &sciezkaPlikuUstawien) {
    std::ifstream plik(sciezkaPlikuUstawien);

    if (!plik.is_open()) {
        throw BladOdczytuPliku("Nie mozna otworzyc pliku z konfiguracja symulacji!");
    }

    std::string linia;
    while (std::getline(plik, linia)) {
        int pos = linia.find('=');

        std::string klucz = linia.substr(0, pos);
        std::string wartosc = linia.substr(pos + 1);

        try {
            if (klucz == "wysokoscPokoju") wysokoscPokoju = std::stof(wartosc);
            else if (klucz == "szerokoscPokoju") szerokoscPokoju = std::stof(wartosc);
            else if (klucz == "glebokoscPokoju") glebokoscPokoju = std::stof(wartosc);
            else if (klucz == "mocMaksymalnaGrzejnika") mocMaksymalnaGrzejnika = std::stof(wartosc);
            else if (klucz == "czasProbkowania") czasProbkowania = std::stof(wartosc);
            else if (klucz == "liczbaIteracji") liczbaIteracji = std::stoi(wartosc);
            else if (klucz == "zadanaTemperatura") zadanaTemperatura = std::stof(wartosc);
            else if (klucz == "regulator") regulator = std::stoi(wartosc);
            else {
                std::cout << "Nieznany parametr: " << klucz << " o wartosci: " << wartosc << std::endl;
            }
            // if (regulator != 1 && regulator != 2) {
            //     std::cout << "Regulator: " << regulator;
            //     throw NiepoprawnyRegulator("Nieprawidlowy kod regulatora");
            // }
        } catch (const std::invalid_argument& e) {
            std::cout << "Niepoprawny format liczby: " << klucz << " = " << wartosc << std::endl;
            std::cout << "Zostana uzyte domyslne wartosci konfiguracji" << std::endl;
            ustawWartosciDomyslne();
        } catch (const std::out_of_range& e) {
            std::cout << "Liczba poza zakresem: " << klucz << " = " << wartosc << std::endl;
            std::cout << "Zostana uzyte domyslne wartosci konfiguracji" << std::endl;
            ustawWartosciDomyslne();
        }
    }

    plik.close();

    if (wysokoscPokoju <= 0) {
        std::cout << "Wysokosc pokoju musi byc dodatnia. Zostanie uzyta wartosc domyslna" << std::endl;
        wysokoscPokoju = 3.0;
    }
    if (szerokoscPokoju <= 0) {
        std::cout << "Szerokosc pokoju musi byc dodatnia. Zostanie uzyta wartosc domyslna" << std::endl;
        szerokoscPokoju = 4.0;
    }
    if (glebokoscPokoju <= 0) {
        std::cout << "Glebokosc pokoju musi byc dodatnia. Zostanie uzyta wartosc domyslna" << std::endl;
        glebokoscPokoju = 5.0;
    }
    if (mocMaksymalnaGrzejnika <= 0) {
        std::cout << "Moc maksymalna grzejnika musi byc dodatnia. Zostanie uzyta wartosc domyslna" << std::endl;
        mocMaksymalnaGrzejnika = 1000.0;
    }
    if (czasProbkowania <= 0) {
        std::cout << "Czas probkowania musi byc dodatni. Zostanie uzyta wartosc domyslna" << std::endl;
        wysokoscPokoju = 5.0;
    }
    if (liczbaIteracji <= 0) {
        std::cout << "Liczba iteracji musi byc dodatnia. Zostanie uzyta wartosc domyslna" << std::endl;
        wysokoscPokoju = 1000.0;
    }
}

void Konfiguracja::ustawWartosciDomyslne() {
    wysokoscPokoju = 3.0;
    szerokoscPokoju = 4.0;
    glebokoscPokoju = 5.0;
    mocMaksymalnaGrzejnika = 1000.0;
    czasProbkowania = 5.0;
    liczbaIteracji = 1000;
    zadanaTemperatura = 20.0;
    regulator = 1;
}
