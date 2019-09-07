#ifndef PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H


class GeneratorsCreator {
private:
    bool createClientGenerator() const;

public:
    GeneratorsCreator();

    ~GeneratorsCreator();

    bool createGenerators() const;
};


#endif //PRIMAVERA_CONCURRENTE_GENERATORSCREATOR_H
