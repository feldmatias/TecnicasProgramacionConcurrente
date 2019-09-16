#ifndef PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H


#include "../concurrency/Process.h"

class GeneratorsCreator {
private:
    /**
     * Create client generator.
     * Returns true if was created (child process), false otherwise.
     */
    bool createClientGenerator() const;

public:
    /**
     * Constructor.
     */
    GeneratorsCreator();

    /**
     * Destructor.
     */
    ~GeneratorsCreator();

    /**
     * Create client and internet generators.
     * Returns empty if a generator was created (child process), ProcessNames otherwise.
     */
    ProcessNames createGenerators() const;
};


#endif //PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
