#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "pomieszczenie.h"


class Symulacja {
    private:
        Pomieszczenie pokoj;

        std::vector<float> czasy;
        std::vector<float> temperatury;

        void iteracja(float dT);

    public:
        Symulacja(
            float wysokoscPokoju,
            float szerokoscPokoju,
            float glebokoscPokoju
            // float tempZewnetrzna = -20.00
        );

        void przebieg(int ileIteracji, float dT);
        void zapiszWyniki(const std::string &sciezkaPliku);

};
