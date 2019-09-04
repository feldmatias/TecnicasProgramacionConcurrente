

#include "DistributionCenter.h"
#include "../flower/FlowersBox.h"
#include "../concurrency/Fifo.h"
#include "../../config/ConfigFiles.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../utils/file/ReadOnlyFile.h"

DistributionCenter::DistributionCenter(const ActorInfo& info) :
    Actor(info), storage(info.getName()) {
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
    if(storage.hasData()){
        std::string line = storage.getLine();
        WriteOnlyFile out("out.test");
        out.writeLine(line);
    }
    return FlowersBox("hola", 2,6);
}

DistributionCenter::~DistributionCenter() = default;
