
#include "ClientGenerator.h"
#include "../utils/common/Random.h"
#include "../actors/PointOfSale.h"
#include "../ConfigFiles.h"
#include "../utils/common/TimeSimulator.h"

ClientGenerator::ClientGenerator() {
    lastClient = 0;
}

ClientGenerator::~ClientGenerator() = default;

void ClientGenerator::doWork(Data data) {
    if (Random::probability(config.clientGeneratorRate())) {
        Order client = createClient();
        sendClient(client);
    }
    TimeSimulator::simulate();
}

Order ClientGenerator::createClient() {
    Order client(CLIENT_NAME + std::to_string(lastClient));
    lastClient++;

    for (const FlowerType &type : FlowerType::all()) {
        int count = Random::generate(config.minFlowerAmount(), config.maxFlowerAmount());
        client.addFlowers(type, count);
    }

    return client;
}

void ClientGenerator::sendClient(const Order &client) {
    int salePointNumber = Random::generate(actorsConfig.numberOfPointsOfSale());
    std::string salePoint = PointOfSale::getName(salePointNumber);

    clientSender.sendClient(salePoint, client);
}

std::string ClientGenerator::name() {
    return CLIENTS_GENERATOR;
}
