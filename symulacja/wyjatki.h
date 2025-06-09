#pragma once
#include <stdexcept>
#include <string>


class BladOdczytuPliku : public std::runtime_error {
    public:
        BladOdczytuPliku(const std::string& msg) 
            : std::runtime_error("Blad odczytu pliku: " + msg) {}
};

class BladWartosciKonfiguracji : public std::runtime_error {
    public:
        BladWartosciKonfiguracji(const std::string& msg) 
            : std::runtime_error("Blad wartosci w konfiguracji: " + msg) {}
};
