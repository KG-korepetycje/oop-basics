#include "karta.h"

// const char kolory[] = { 3, 4, 5, 6 }; //Wyjątek: jeśli symbole kolorów kart nie będą wyświetlać się poprawnie, możesz je zamienić np. na litery. 
const char kolory[] = { 'K', 'P', 'T', 'C' };
const char figury[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };
const int wartosci[] = { 2,   3,   4,   5,   6,   7 ,  8,   9,  10,   2,   3,   4,  11 };

Karta::Karta(int _kolor, int _wartosc)
: kolor(kolory[0]), figura(figury[0]), wartosc(wartosci[0]) {
    setKolor(_kolor);
    setWartosc(_wartosc);
}

void Karta::setKolor(int _kolor) {
    if (_kolor < 4 && _kolor >= 0) {
        kolor = kolory[_kolor];
    }
}

void Karta::setWartosc(int _wartosc) {
    if (_wartosc < 13 && _wartosc >= 0) {
        figura = figury[_wartosc];
        wartosc = wartosci[_wartosc];
    }
}
