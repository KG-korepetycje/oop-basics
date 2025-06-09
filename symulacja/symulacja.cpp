#include "symulacja.h"
#include "dwustawny.h"
#include "pid.h"


Symulacja::Symulacja(const Konfiguracja &konfiguracja)
    : pokoj(
        konfiguracja.getWysokoscPokoju(),
        konfiguracja.getSzerokoscPokoju(),
        konfiguracja.getGlebokoscPokoju()
    )
    , grzejnik(konfiguracja.getMocMaksymalnaGrzejnika())
{
    if (konfiguracja.getRegulator() == 1)
        regulator = new Dwustawny(pokoj, grzejnik, konfiguracja.getZadanaTemperatura());
    else if (konfiguracja.getRegulator() == 2)
        regulator = new PID(pokoj, grzejnik, konfiguracja.getZadanaTemperatura());
    else
        regulator = nullptr;
}

Symulacja::Symulacja(
    float wysokoscPokoju,
    float szerokoscPokoju,
    float glebokoscPokoju,
    float mocMaksymalnaGrzejnika,
    float zadanaTemperatura,
    bool czyRegulatorDwustawny
    // float tempZewnetrzna = -20.00
)
    : pokoj(wysokoscPokoju,szerokoscPokoju,glebokoscPokoju)
    , grzejnik(mocMaksymalnaGrzejnika)
{
    if (czyRegulatorDwustawny)
        regulator = new Dwustawny(pokoj, grzejnik, zadanaTemperatura);
    else
        regulator = new PID(pokoj, grzejnik, zadanaTemperatura);
}

Symulacja::~Symulacja() {
    delete regulator;
}

void Symulacja::iteracja(float dT) {
    if (regulator != nullptr)
        regulator->aktualizuj(dT);
    pokoj.dodajCieplo(grzejnik.emitujCieplo(dT));
    pokoj.aktualizuj(dT);
    std::cout << "Aktualna temperatura pokoju: " << pokoj.getTemperatura() << "\n";
}

void Symulacja::przebieg(int ileIteracji, float dT) {
    for (int i = 0; i < ileIteracji; i++) {
        czasy.push_back(i * dT);
        temperatury.push_back(pokoj.getTemperatura());
        nastawyGrzejnika.push_back(grzejnik.getMocAktualna());
        iteracja(dT);
    }
}

void Symulacja::zapiszWyniki(const std::string &sciezkaPliku) {
    std::ofstream plikWynikowy;
    plikWynikowy.open(sciezkaPliku, std::ofstream::out);
    plikWynikowy << "Iteracja;Czas;Temperatura;Nastawa Grzejnika\n";
    int liczbaIteracji = czasy.size();
    for (int i = 0; i < liczbaIteracji; i++) {
        plikWynikowy << i << ";" << std::fixed << std::setprecision(1) << czasy[i] << ";" << temperatury[i] << ";" << std::setprecision(2) << nastawyGrzejnika[i] << "\n";
    }
    plikWynikowy.close();
}
