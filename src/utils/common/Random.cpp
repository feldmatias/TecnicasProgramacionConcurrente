

#include <random>
#include "Random.h"

int Random::generate(int max) {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<int> distribution(0, max - 1);

    return distribution(generator);
}
