#include "Randomised.h"
#include <random>

int randomPrice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1, 500);
    return dist(gen);
}