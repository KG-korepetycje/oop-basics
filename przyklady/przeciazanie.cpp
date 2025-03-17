#include <iostream>

double funkcja(double x) {
    return x + 10.123;
}

double funkcja(int n) {
    return n + 10;
}

double funkcja(int n, int m) {
    return n * m;
}

double funkcja(double a, std::string napis) {
    std::cout << napis << std::endl;
    return a * 5;
}

int main() {
    std::cout << funkcja(16) << std::endl;
    std::cout << funkcja(5, 8) << std::endl;
    std::cout << funkcja(0.2, "Funkcja") << std::endl;
    std::cout << funkcja(5.5) << std::endl;
    // std::cout << funkcja("Ala ma kota") << std::endl; // blad kompilacji

    return 0;
}

