#include "symulacja.h"


Symulacja::Symulacja(
    float wysokoscPokoju,
    float szerokoscPokoju,
    float glebokoscPokoju
    // float tempZewnetrzna = -20.00
) : pokoj(wysokoscPokoju,szerokoscPokoju,glebokoscPokoju) {}


void Symulacja::iteracja(float dT) {
    pokoj.aktualizuj(dT);
    std::cout << "Aktualna temperatura pokoju: " << pokoj.getTemperatura() << "\n";
}

void Symulacja::przebieg(int ileIteracji, float dT) {
    for (int i = 0; i < ileIteracji; i++) {
        czasy.push_back(i * dT);
        temperatury.push_back(pokoj.getTemperatura());
        iteracja(dT);
    }
}

void Symulacja::zapiszWyniki(const std::string &sciezkaPliku) {
    std::ofstream plikWynikowy;
    plikWynikowy.open(sciezkaPliku, std::ofstream::out);
    plikWynikowy << "Iteracja;Czas;Temperatura\n";
    int liczbaIteracji = czasy.size();
    for (int i = 0; i < liczbaIteracji; i++) {
        plikWynikowy << i << ";" << std::fixed << std::setprecision(1) << czasy[i] << ";" << temperatury[i] << "\n";
    }
    plikWynikowy.close();
}
