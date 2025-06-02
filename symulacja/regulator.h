#pragma once
#include <iostream>

#include "pomieszczenie.h"
#include "grzejnik.h"


class Regulator {
    private:
        virtual float steruj(float dT) = 0;

    protected:
        Pomieszczenie& pokoj;  // agregacja
        Grzejnik& grzejnik;  // agregacja
        float zadanaTemperatura;

    public:
        Regulator(
            Pomieszczenie& pokoj,
            Grzejnik& grzejnik,
            float zadanaTemperatura
        )
            : pokoj(pokoj)
            , grzejnik(grzejnik)
            , zadanaTemperatura(zadanaTemperatura) {}
        void aktualizuj(float dT);

};
