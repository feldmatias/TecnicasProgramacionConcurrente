//
// Created by guille on 3/9/19.
//

#include <string>
#include "FlowersBox.h"

FlowersBox::FlowersBox(std::string producer, int roses, int tulips) : producer(std::move(producer)),roses(roses), tulips(tulips) {
}

const std::string &FlowersBox::getProducer() const {
    return producer;
}

int FlowersBox::getRoses() const {
    return roses;
}

int FlowersBox::getTulips() const {
    return tulips;
}

FlowersBox::~FlowersBox() = default;
