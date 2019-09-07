

#ifndef PRIMAVERA_CONCURRENTE_RANDOM_H
#define PRIMAVERA_CONCURRENTE_RANDOM_H


class Random {
public:

    /**
     * Generate a random number between 0 and max - 1.
     */
    static int generate(int max);

    /**
     * Generate a random number between min and max.
     */
    static int generate(int min, int max);

    /**
     * Calculate a random and return if is below probability.
     */
    static bool probability(int probability);
};


#endif //PRIMAVERA_CONCURRENTE_RANDOM_H
