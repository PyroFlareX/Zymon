#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <ctime>
#include <iostream>

class Random
{
    public:
		Random() : m_randomEngine(std::time(nullptr)) {}

        int intInRange(int low, int high)
        {
            std::uniform_int_distribution<int> dist(low, high);
            return dist(m_randomEngine);
        }
        float floatInRange(float low, float high)
        {
            std::uniform_real_distribution<float> dist(low, high);
            return dist(m_randomEngine);
        }
    protected:

    private:
        std::mt19937 m_randomEngine;
};

#endif // RANDOM_H
