#include <iostream>

class Czas
{
    private:
        int godziny;
        int minuty;
        int sekundy;

    public:
        int pobierzGodziny();
        int pobierzMinuty();
        int pobierzSekundy();

        bool ustawGodziny(int nowaWartosc);
        bool ustawMinuty(int nowaWartosc);
        bool ustawSekundy(int nowaWartosc);
        
        void wyswietl();
    
};
