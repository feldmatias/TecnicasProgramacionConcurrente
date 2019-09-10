
#include "ClientGenerator.h"
#include "../utils/common/Random.h"
#include "../actors/PointOfSale.h"

ClientGenerator::ClientGenerator() {
    lastClient = 0;
    lastInternetOrder = 0;
}

ClientGenerator::~ClientGenerator() = default;

void ClientGenerator::doWork() {
    if (Random::probability(config.clientGeneratorRate())) {
        Order client = createClient();
        sendClient(client);
        return;
    }
    if (Random::probability(config.clientGeneratorRate())) {
        Order order = createInternetOrder();
        sendClient(order);
    }
}

void ClientGenerator::finish() {
 // Do nothing
}

Order ClientGenerator::createClient() {
    Order client(CLIENT_NAME + std::to_string(lastClient));
    lastClient++;

    for (const FlowerType& type : FlowerType::all()) {
        int count = Random::generate(config.minFlowerAmount(), config.maxFlowerAmount());
        client.addFlowers(type, count);
    }

    return client;
}

Order ClientGenerator::createInternetOrder() {
    Order client(INTERNET_NAME + std::to_string(lastClient));
    lastInternetOrder++;

    for (const FlowerType& type : FlowerType::all()) {
        int count = Random::generate(config.minFlowerAmount(), config.maxFlowerAmount());
        client.addFlowers(type, count);
    }

    return client;
}

void ClientGenerator::sendClient(const Order& client) {
    int salePointNumber = Random::generate(actorsConfig.numberOfPointsOfSale());
    std::string salePoint = PointOfSale::getClientName(salePointNumber);

    clientSender.sendOrder(salePoint, client);
}
