#include <iostream>
// #include "czas.h"
#include "harmonogram.h"

// int main() {
//     Czas czas1;
//     Czas czas2;

//     // // czas1.ustawCzas(23, 40, 37);
//     czas1.ustawCzas(9, 14, 1);
//     czas2.ustawCzas(50, 26, 3);

//     std::cout << "czas1 == czas2: " << (czas1 == czas2) << std::endl;
//     std::cout << "czas1 != czas2: " << (czas1 != czas2) << std::endl;
//     std::cout << "czas1 < czas2: " << (czas1 < czas2) << std::endl;
//     std::cout << "czas1 >= czas2: " << (czas1 >= czas2) << std::endl;

//     Czas czas3 = czas1 + czas2;
//     std::cout << "Czas3\n";
//     czas3.wyswietl();

//     czas1 += czas2;
//     std::cout << "Czas1\n";
//     czas1.wyswietl();
    

//     // Czas czas1;
//     // Czas czas2;

//     czas1.ustawCzas(9, 14, 1);
//     czas2.ustawCzas(9, 14, 1);

//     std::cout << "czas1 == czas2: " << (czas1 == czas2) << std::endl;

//     // std::cout << "czas1 < czas2: " << (czas1 < czas2) << std::endl;
//     return 0;
// }

int main() {
    Harmonogram h;

    Czas czas1;
    czas1.ustawCzas(9, 14, 1);

    h.dodajCzas(czas1);
    h.wypiszZestawienie();

    Czas czas2;
    czas2.ustawCzas(15, 10, 5);

    h.dodajCzas(czas2);
    h.wypiszZestawienie();

    Czas czas3 = h.pobierzCzas(0);
    czas3.ustawCzas(8, 8, 8);

    h.wypiszZestawienie();
    return 0;
}
