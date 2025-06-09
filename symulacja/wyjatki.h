#include <exception>
#include <string>

class BladOdczytuPliku : public std::exception {
    std::string komunikat;
public:
    BladOdczytuPliku(const std::string& msg) : komunikat(msg) {}
    const char* what() const noexcept override {
        return komunikat.c_str();
    }
};


class NiepoprawnyRegulator : public std::exception {
    std::string komunikat;
public:
    NiepoprawnyRegulator(const std::string& msg) : komunikat(msg) {}
    const char* what() const noexcept override {
        return komunikat.c_str();
    }
};
