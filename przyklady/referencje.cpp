#include <iostream>

int main() {
    double liczba = 0;
    double& refLiczba = liczba;

    std::cout << "liczba: " << liczba << "\n";
    std::cout << "&liczba: " << &liczba << "\n";
    std::cout << "refLiczba: " << refLiczba << "\n\n\n";

    liczba++;
    std::cout << "refLiczba: " << refLiczba << "\n\n\n";

    refLiczba++;
    std::cout << "liczba: " << liczba << "\n";
    std::cout << "refLiczba: " << refLiczba << "\n\n\n";

    return 0;
}

