//
// Created by guille on 3/9/19.
//

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSBOX_H
#define PRIMAVERA_CONCURRENTE_FLOWERSBOX_H


class FlowersBox {
private:
    int roses, tulips;
    std::string producer;
public:
    FlowersBox(std::string producer, int roses, int tulips);

    const std::string &getProducer() const;

    int getRoses() const;

    int getTulips() const;

    ~FlowersBox();
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSBOX_H
