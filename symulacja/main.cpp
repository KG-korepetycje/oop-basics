#include <iostream>

#include "symulacja.h"

int main() {

    float wysokoscPokoju = 3;
    float szerokoscPokoju = 5;
    float glebokoscPokoju = 4;
    float mocMaksymalnaGrzejnika = 1000;
    float zadanaTemperatura = 22;
    bool czyRegulatorDwustawny = false;
    int liczbaIteracji = 800;
    float dT = 5.0;

    Symulacja symulacja(
        wysokoscPokoju,
        szerokoscPokoju,
        glebokoscPokoju,
        mocMaksymalnaGrzejnika,
        zadanaTemperatura,
        czyRegulatorDwustawny
    );
    symulacja.przebieg(liczbaIteracji, dT);
    symulacja.zapiszWyniki("./symulacja-wyniki/wyniki_pid.csv");

    return 0;
}
