#include "grzejnik.h"


Grzejnik::Grzejnik(float mocMaksymalna)
    : mocMaksymalna(mocMaksymalna) { }

void Grzejnik::ustawMoc(float nowaMoc) {
    if (nowaMoc < 0.0)
        mocAktualna = 0.0;
    else {
        if (nowaMoc > 1.0)
            mocAktualna = 1.0;
        else
            mocAktualna = nowaMoc;
    }
}

float Grzejnik::emitujCieplo(float dT) {
    return mocMaksymalna * mocAktualna * dT;
}
