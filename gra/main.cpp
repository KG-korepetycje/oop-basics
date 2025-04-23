#include <iostream>

#include "kasyno.h"
#include "gracz.h"


int main() {
    Kasyno kasyno;

    /* initialize random seed: */
    srand(time(NULL));

    kasyno.graj();
    // Gracz gracz;

    // gracz.wezKarte(kasyno.dajKarte());
    // gracz.wezKarte(kasyno.dajKarte());

    // gracz.wyswietlKarty();
    // for(int i = 0; i < 52; i++) {
    //     kasyno.talia[i].wypisz();
    //     std::cout << "\n";
    // }

    return 0;
}
