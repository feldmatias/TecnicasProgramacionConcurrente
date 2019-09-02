

#ifndef PRIMAVERA_CONCURRENTE_ACTORINFO_H
#define PRIMAVERA_CONCURRENTE_ACTORINFO_H


#include <string>

class ActorInfo {
private:
    std::string name;

public:
    explicit ActorInfo(std::string&& name);

    ~ActorInfo();

    std::string getName() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORINFO_H
