#pragma once
#include <iostream>

#include "gracz.h"

enum Strategia {
    RYZYKUJACA = 19,
    NORMALNA = 17,
    ZACHOWAWCZA = 15
};


class Bot : public Gracz {
    private:
        int limitPunktow;

    public:
        void ustawStrategie(Strategia _strategia);
        bool czyPasuje();
};
