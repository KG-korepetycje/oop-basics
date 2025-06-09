#pragma once
#include <string>

enum class TypRegulatora {
    DWUSTAWNY,
    PID,
    BRAK
};

class Konfiguracja {
    public:
        // Parametry z wartościami domyślnymi (zgodnie z poleceniem)
        float wysokoscPokoju = 3.0;
        float szerokoscPokoju = 4.0;
        float glebokoscPokoju = 5.0;
        float mocMaksymalnaGrzejnika = 1000.0;
        float czasProbkowania = 5.0;
        int liczbaIteracji = 1000;
        float zadanaTemperatura = 20.0;
        TypRegulatora typRegulatora = TypRegulatora::PID;

        Konfiguracja() = default; 
        Konfiguracja(const std::string& sciezkaPlikuUstawien);
};
