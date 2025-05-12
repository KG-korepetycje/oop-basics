#include "bot.h"
#include "kasyno.h"

void Bot::ustawStrategie(Strategia _strategia) {
    limitPunktow = _strategia;
}

bool Bot::czyPasuje() {
    if (wartoscKart > limitPunktow) {
        spasowal = true;
        return true;
    }

    wezKarte(kasyno->dajKarte());
    if (wartoscKart >= 21) {
        spasowal = true;
    }

    return false;
}
