#ifndef PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
#define PRIMAVERA_CONCURRENTE_FLOWERTYPE_H


#include <string>
#include <vector>

class FlowerType {
private:
    std::string type;

public:
    static std::vector<FlowerType> all();

    static FlowerType Tulip();

    static FlowerType Rose();

    explicit FlowerType(std::string type);

    ~FlowerType();

    friend std::ostream& operator<<(std::ostream& os, const FlowerType& flowerType);

    bool operator==(const FlowerType &other) const;

    std::string getType() const;
};

namespace std {
    template <>
    struct hash<FlowerType> {
        std::size_t operator()(const FlowerType& key) const {
            return hash<string>()(key.getType());
        }
    };
}

#endif //PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
