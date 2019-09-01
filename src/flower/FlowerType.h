

#ifndef PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
#define PRIMAVERA_CONCURRENTE_FLOWERTYPE_H


#include <string>

class FlowerType {
private:
    std::string type;

public:
    static FlowerType Tulip();

    static FlowerType Rose();

    FlowerType(std::string type);

    ~FlowerType();

    friend std::ostream& operator<<(std::ostream& os, const FlowerType& flowerType);
};

#endif //PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
