#include <iostream>

#include "konfiguracja.h"
#include "symulacja.h"
#include "wyjatki.h"

int main() {

    // float wysokoscPokoju = 3;
    // float szerokoscPokoju = 5;
    // float glebokoscPokoju = 4;
    // float mocMaksymalnaGrzejnika = 1000;
    // float zadanaTemperatura = 22;
    // bool czyRegulatorDwustawny = false;
    // int liczbaIteracji = 800;
    // float dT = 5.0;
    
    // Symulacja symulacja(
    //     wysokoscPokoju,
    //     szerokoscPokoju,
    //     glebokoscPokoju,
    //     mocMaksymalnaGrzejnika,
    //     zadanaTemperatura,
    //     czyRegulatorDwustawny
    // );

    // symulacja.przebieg(liczbaIteracji, dT);
    // symulacja.zapiszWyniki("./symulacja-wyniki/wyniki_pid.csv");

    Konfiguracja konfiguracja;

    try {
        konfiguracja = Konfiguracja("./symulacja/ustawienia.txt");
        std::cout << "Konfiguracja wczytana z pliku 'ustawienia.txt'." << std::endl;
    } catch (const BladOdczytuPliku& e) {
        std::cerr << "Blad krytyczny: " << e.what() << std::endl;
        std::cerr << "Program zostanie zakonczony." << std::endl;
        return 1;
    } catch (const BladWartosciKonfiguracji& e) {
        std::cerr << "Wystapil blad podczas wczytywania konfiguracji: " << e.what() << std::endl;
        std::cerr << "Symulacja zostanie uruchomiona z parametrami domyslnymi." << std::endl;
        // Obiekt 'konfiguracja' nie zostal zmieniony i wciaz ma wartosci domyslne
    }

    Symulacja symulacja(konfiguracja);
    symulacja.przebieg(konfiguracja.liczbaIteracji, konfiguracja.czasProbkowania);
    symulacja.zapiszWyniki("./symulacja-wyniki/wyniki.csv");
    std::cout << "Symulacja zakonczona pomyslnie." << std::endl;

    return 0;
}
