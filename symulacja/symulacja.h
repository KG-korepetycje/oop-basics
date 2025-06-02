#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "pomieszczenie.h"
#include "grzejnik.h"
#include "regulator.h"


class Symulacja {
    private:
        Pomieszczenie pokoj;
        Grzejnik grzejnik;
        Regulator* regulator;

        std::vector<float> czasy;
        std::vector<float> temperatury;
        std::vector<float> nastawyGrzejnika;

        void iteracja(float dT);

    public:
        Symulacja(
            float wysokoscPokoju,
            float szerokoscPokoju,
            float glebokoscPokoju,
            float mocMaksymalnaGrzejnika,
            float zadanaTemperatura,
            bool czyRegulatorDwustawny
            // float tempZewnetrzna = -20.00
        );
        ~Symulacja();

        void przebieg(int ileIteracji, float dT);
        void zapiszWyniki(const std::string &sciezkaPliku);

};
