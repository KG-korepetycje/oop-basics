#include <iostream>

struct prostokat {
    double wysokosc;
    double szerokosc;
};

void ustaw_boki(struct prostokat _figura, double _wys, double _szer) {
    // Tutaj trafia KOPIA
    _figura.wysokosc = _wys;
    _figura.szerokosc = _szer;
    std::cout << "Adres kwadratu w ustaw_boki(): " << &_figura << "\n";
}

void ustaw_boki_dobre(struct prostokat* _figura, double _wys, double _szer) {
    // Tutaj trafia ADRES oryginalu
    _figura->wysokosc = _wys; // To samo co: (*_figura).wysokosc = _wys;
    _figura->szerokosc = _szer;
    std::cout << "Adres kwadratu w ustaw_boki_dobre(): " << _figura << "\n";
}

int main() {
    struct prostokat kwadrat = {1, 1};
    std::cout << "Adres kwadratu w main(): " << &kwadrat << "\n";
    ustaw_boki_dobre(&kwadrat, 5, 5);
    std::cout << "Wysokosc: " << kwadrat.wysokosc << "\n";
    std::cout << "Szerokosc: " << kwadrat.szerokosc << "\n";
}

