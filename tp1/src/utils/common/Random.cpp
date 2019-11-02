

#include <random>
#include "Random.h"

int Random::generate(int max) {
    return generate(0, max - 1);
}

int Random::generate(int min, int max) {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

bool Random::probability(int probability) {
    int random = generate(100);
    return random < probability;
}

