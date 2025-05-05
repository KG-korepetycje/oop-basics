#include <iostream>

#include "kasyno.h"


int main() {
    /* initialize random seed: */
    srand(time(NULL));

    Kasyno kasyno;
    kasyno.graj();

    return 0;
}
