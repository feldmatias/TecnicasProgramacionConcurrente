#ifndef PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H


#include "../concurrency/Process.h"

class GeneratorsCreator {
private:
    /**
     * Create client generator.
     */
    ProcessInfo createClientGenerator() const;

    /**
     * Create internet orders generator.
     */
    ProcessInfo createInternetGenerator() const;

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
     * Returns empty if a generator was created (child process), Process infos otherwise.
     */
    ProcessInfoList createGenerators() const;
};


#endif //PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
