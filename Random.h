#pragma once
#include <random>

class Random {
public:
    Random();
    int getRandomNumber(int min, int max);
    static int random(int min, int max); // Static method for easier usage
private:
    std::mt19937 m_rng; // Mersenne Twister engine
};