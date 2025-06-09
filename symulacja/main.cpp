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
    // 
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

    try {
        Konfiguracja konfig("./symulacja/ustawienia.txt");
        Symulacja symulacja(konfig);
        symulacja.przebieg(konfig.getLiczbaIteracji(), konfig.getCzasProbkowania());
        symulacja.zapiszWyniki("./symulacja-wyniki/wyniki_pid.csv");
    } catch (BladOdczytuPliku& blad) {
        std::cout << "Blad: " << blad.what() << std::endl;
        return 0;
    }

    return 0;
}
