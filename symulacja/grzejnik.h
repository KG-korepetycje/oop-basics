#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "pomieszczenie.h"


class Grzejnik {
    private:
        float mocMaksymalna;
        float mocAktualna = 0.0;  // Domyslnie grzejnik wylaczony

    public:
        Grzejnik(float mocMaksymalna);

        float getMocAktualna() const { return mocAktualna; }

        void ustawMoc(float nowaMoc);
        float emitujCieplo(float dT);
};
