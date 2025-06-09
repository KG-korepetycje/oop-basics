#include "konfiguracja.h"
#include "wyjatki.h"
#include <fstream>
#include <iostream>

Konfiguracja::Konfiguracja(const std::string& sciezkaPlikuUstawien) {
    std::ifstream plik(sciezkaPlikuUstawien);

    if (!plik.is_open()) {
        throw BladOdczytuPliku("Nie mozna otworzyc pliku '" + sciezkaPlikuUstawien + "'");
    }

    std::string linia;
    int nrLinii = 0;
    try {
        while (std::getline(plik, linia)) {
            nrLinii++;
            int pos = linia.find('=');
            if (pos == std::string::npos) {  // Sprawdzenie, czy funkcja find() nie zwrocila bledu
                throw BladWartosciKonfiguracji("Brak znaku '=' w linii " + std::to_string(nrLinii));
            }

            std::string klucz = linia.substr(0, pos);
            std::string wartosc = linia.substr(pos + 1);

            if (klucz == "wysokoscPokoju") wysokoscPokoju = std::stof(wartosc);
            else if (klucz == "szerokoscPokoju") szerokoscPokoju = std::stof(wartosc);
            else if (klucz == "glebokoscPokoju") glebokoscPokoju = std::stof(wartosc);
            else if (klucz == "mocMaksymalnaGrzejnika") mocMaksymalnaGrzejnika = std::stof(wartosc);
            else if (klucz == "czasProbkowania") czasProbkowania = std::stof(wartosc);
            else if (klucz == "liczbaIteracji") liczbaIteracji = std::stoi(wartosc);
            else if (klucz == "zadanaTemperatura") zadanaTemperatura = std::stof(wartosc);
            else if (klucz == "regulator") {
                int typ = std::stoi(wartosc);
                if (typ == 1) typRegulatora = TypRegulatora::DWUSTAWNY;
                else if (typ == 2) typRegulatora = TypRegulatora::PID;
                else {
                    typRegulatora = TypRegulatora::BRAK;
                    std::cout << "Ostrzezenie: Nieprawidlowy typ regulatora (" << wartosc
                        << "). Symulacja zostanie uruchomiona bez regulatora." << std::endl;
                }
            }
        }
    } catch (const std::invalid_argument& e) {
        throw BladWartosciKonfiguracji("Nieprawidlowy format danych w linii " + std::to_string(nrLinii) + ": " + linia);
    } catch (const std::out_of_range& e) {
        throw BladWartosciKonfiguracji("Wartosc poza zakresem w linii " + std::to_string(nrLinii) + ": " + linia);
    }

    plik.close();
    
    // Walidacja po wczytaniu wszystkich danych
    if (
        wysokoscPokoju <= 0 ||
        szerokoscPokoju <= 0 ||
        glebokoscPokoju <= 0 || 
        mocMaksymalnaGrzejnika <= 0 ||
        czasProbkowania <= 0 ||
        liczbaIteracji <= 0
    ) {
        throw BladWartosciKonfiguracji("Wartosci parametrow (wymiary, moc, dt, liczba iteracji) musza byc dodatnie.");
    }
}
