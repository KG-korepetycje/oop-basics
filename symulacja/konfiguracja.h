#pragma once
#include <iostream>
#include <fstream>


class Konfiguracja {
    private:
        float wysokoscPokoju;
        float szerokoscPokoju;
        float glebokoscPokoju;
        float mocMaksymalnaGrzejnika;
        float czasProbkowania;
        int liczbaIteracji;
        float zadanaTemperatura;
        int regulator;

        void ustawWartosciDomyslne();

    public:
        Konfiguracja(const std::string &sciezkaPlikuUstawien);
        
        float getWysokoscPokoju() const { return wysokoscPokoju; }
        float getSzerokoscPokoju() const { return szerokoscPokoju; }
        float getGlebokoscPokoju() const { return glebokoscPokoju; }
        float getMocMaksymalnaGrzejnika() const { return mocMaksymalnaGrzejnika; }
        float getCzasProbkowania() const { return czasProbkowania; }
        int getLiczbaIteracji() const { return liczbaIteracji; }
        float getZadanaTemperatura() const { return zadanaTemperatura; }
        int getRegulator() const { return regulator; }
};
