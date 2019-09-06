
#ifndef PRIMAVERA_CONCURRENTE_FIFO_H
#define PRIMAVERA_CONCURRENTE_FIFO_H

#include <string>
#include <memory>
#include "../utils/file/File.h"

class Fifo {
private:
    std::string name;
    std::unique_ptr<File> file;

public:
    static std::string filename(const std::string& name);

    explicit Fifo(const std::string& name);

    ~Fifo();

    std::string getLine();
};


#endif //PRIMAVERA_CONCURRENTE_FIFO_H
