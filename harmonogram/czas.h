#include <iostream>

#pragma once

class Czas {

    private:
        int godziny;
        int minuty;
        int sekundy;

        void ustawGodziny(int nowaWartosc);
        void ustawMinuty(int nowaWartosc);
        void ustawSekundy(int nowaWartosc);

    public:
        int pobierzGodziny();
        int pobierzMinuty();
        int pobierzSekundy();

        void ustawCzas(int sek, int min, int godz);
        void ustawCzas(int sek, int min);
        void ustawCzas(int sek);
        // void ustawCzas(int sek, int min = 0, int godz = 0);

        Czas operator+(Czas& _czas);
        void operator+=(Czas& _czas); // nie potrzeba nic zwracac, tylko aktualizacja obecnego czasu

        bool operator==(Czas& _czas);
        bool operator<(Czas& _czas);
        bool operator<=(Czas& _czas);
        bool operator>(Czas& _czas);
        bool operator>=(Czas& _czas);
        bool operator!=(Czas& _czas);

        void wyswietl();
};
