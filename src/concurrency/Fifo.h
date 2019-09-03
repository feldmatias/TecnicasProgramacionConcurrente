
#ifndef PRIMAVERA_CONCURRENTE_FIFO_H
#define PRIMAVERA_CONCURRENTE_FIFO_H

#include <string>
#include <memory>
#include "../utils/file/File.h"

#define FIFO_EXTENSION ".fifo"


class Fifo {
private:
    std::string name;
    std::unique_ptr<File> file;

public:
    explicit Fifo(const std::string& name);

    ~Fifo();

    std::string getLine();

    bool hasData();
};


#endif //PRIMAVERA_CONCURRENTE_FIFO_H
