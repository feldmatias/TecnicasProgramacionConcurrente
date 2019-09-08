#ifndef PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H


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
     * Returns true if a generator was created (child process), false otherwise.
     */
    bool createGenerators() const;
};


#endif //PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
