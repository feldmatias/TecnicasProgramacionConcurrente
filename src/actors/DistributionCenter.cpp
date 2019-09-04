

#include "DistributionCenter.h"
#include "../flower/FlowersBox.h"
#include "../concurrency/Fifo.h"
#include "../../config/ConfigFiles.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../utils/file/ReadOnlyFile.h"

DistributionCenter::DistributionCenter(const ActorInfo& info) :
    Actor(info) {
    //Actor(info), storage(CONFIG_PATH + info.getName()) {
}

void DistributionCenter::doWork() {
    FlowersBox box = getFlowersBox();
    //updateStock(box);
    //sendToPointOfSale();
}

void DistributionCenter::finish() {
    // TODO: implement this
}

FlowersBox DistributionCenter::getFlowersBox(){
    /*Fifo storage(CONFIG_PATH + name);
    if(storage.hasData()){
        std::string line = storage.getLine();
        WriteOnlyFile out(CONFIG_PATH + "out");
        out.writeLine(line);
    }*/
    ReadOnlyFile file(CONFIG_PATH + name + std::string(FIFO_EXTENSION));
    if(file.hasMoreData()){
        std::string line = file.getLine();
        WriteOnlyFile out(CONFIG_PATH + "out");
        out.writeLine(line);
    }
    //parse line
    return FlowersBox("hola", 2,6);
}

DistributionCenter::~DistributionCenter() = default;
