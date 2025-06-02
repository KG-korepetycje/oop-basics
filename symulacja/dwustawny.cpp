#include "dwustawny.h"

float Dwustawny::steruj(float dT) {
    if (pokoj.getTemperatura() < zadanaTemperatura)
        return 1.0;
    return 0.0;
}
