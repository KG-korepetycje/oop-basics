#include "regulator.h"


void Regulator::aktualizuj(float dT) {
    grzejnik.ustawMoc(steruj(dT));
}
