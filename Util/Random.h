#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <ctime>

class Random
{
    public:
        Random() : m_randomEngine.seed(std::time(NULL))

        int intInRange(int low, int high)
        {
            std::uniform_int_distribution<int> dist(low, high);
            return dist(m_randomEngine);
        }
    protected:

    private:
        std::mt19937 m_randomEngine;
};

#endif // RANDOM_H
