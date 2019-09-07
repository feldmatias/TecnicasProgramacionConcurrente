#ifndef PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
#define PRIMAVERA_CONCURRENTE_FLOWERTYPE_H


#include <string>
#include <vector>

class FlowerType {
private:
    std::string type;

public:
    /**
     * Get all flower types.
     */
    static std::vector<FlowerType> all();

    /**
     * Create a tulip.
     */
    static FlowerType Tulip();

    /**
     * Create a rose.
     */
    static FlowerType Rose();

    /**
     * Create a flower type.
     */
    explicit FlowerType(std::string type);

    /**
     * Destructor..
     */
    ~FlowerType();

    /**
     * Add flower type to ostream.
     */
    friend std::ostream& operator<<(std::ostream& os, const FlowerType& flowerType);

    /**
     * Compare to other flower type.
     */
    bool operator==(const FlowerType &other) const;

    /**
     * Get type name.
     */
    std::string getName() const;
};

/**
 * Hash a flower type.
 */
namespace std {
    template <>
    struct hash<FlowerType> {
        std::size_t operator()(const FlowerType& key) const {
            return hash<string>()(key.getName());
        }
    };
}

#endif //PRIMAVERA_CONCURRENTE_FLOWERTYPE_H
