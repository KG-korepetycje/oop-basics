#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "pomieszczenie.h"
#include "grzejnik.h"


class Symulacja {
    private:
        Pomieszczenie pokoj;
        Grzejnik grzejnik;

        std::vector<float> czasy;
        std::vector<float> temperatury;
        std::vector<float> nastawyGrzejnika;

        void iteracja(float dT);

    public:
        Symulacja(
            float wysokoscPokoju,
            float szerokoscPokoju,
            float glebokoscPokoju,
            float mocMaksymalnaGrzejnika
            // float tempZewnetrzna = -20.00
        );

        void przebieg(int ileIteracji, float dT);
        void zapiszWyniki(const std::string &sciezkaPliku);

};
