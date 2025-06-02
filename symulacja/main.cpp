#include <iostream>

#include "symulacja.h"

int main() {

    float wysokoscPokoju = 3;
    float szerokoscPokoju = 5;
    float glebokoscPokoju = 4;
    float mocMaksymalnaGrzejnika = 1000;
    int liczbaIteracji = 50;
    float dT = 5.0;

    Symulacja symulacja(wysokoscPokoju, szerokoscPokoju, glebokoscPokoju, mocMaksymalnaGrzejnika);
    symulacja.przebieg(liczbaIteracji, dT);
    symulacja.zapiszWyniki("./symulacja-wyniki/wyniki.csv");

    return 0;
}
