#pragma once
#include <iostream>

#include "regulator.h"


class Dwustawny : public Regulator {
    private:
        float steruj(float dT) override;  // Jawne sprawdzenie nadpisania z klasy bazowej

    public:
        Dwustawny(
            Pomieszczenie& pokoj,
            Grzejnik& grzejnik,
            float zadanaTemperatura
        ) : Regulator(pokoj, grzejnik, zadanaTemperatura) {}

};
