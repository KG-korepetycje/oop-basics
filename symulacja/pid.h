#pragma once
#include <iostream>

#include "regulator.h"


class PID : public Regulator {
    private:
        const float Kp = 4;
        const float Ki = 0.01;
        const float Kd = 0.5;
        float uchybCalka;
        float uchybPoprzedni;
        float steruj(float dT) override;  // Jawne sprawdzenie nadpisania z klasy bazowej

    public:
        PID(
            Pomieszczenie& pokoj,
            Grzejnik& grzejnik,
            float zadanaTemperatura
        ) : Regulator(pokoj, grzejnik, zadanaTemperatura) {}

};
