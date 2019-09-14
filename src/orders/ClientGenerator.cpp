
#include "ClientGenerator.h"
#include "../utils/common/Random.h"
#include "../actors/PointOfSale.h"
#include "../../config/ConfigFiles.h"

ClientGenerator::ClientGenerator(std::string clientConfigFile) :
    config(clientConfigFile),
    clientName(clientConfigFile == CLIENTS_CONFIG ? CLIENT_NAME : INTERNET_NAME){
    lastClient = 0;
}

ClientGenerator::~ClientGenerator() = default;

void ClientGenerator::receiveData() {
    if (Random::probability(config.clientGeneratorRate())) {
        Order client = createClient();
        sendClient(client);
        return;
    }
}

Order ClientGenerator::createClient() {
    Order client(clientName + std::to_string(lastClient));
    lastClient++;

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

std::string ClientGenerator::name() {
    return "ClientsGenerator";
}
