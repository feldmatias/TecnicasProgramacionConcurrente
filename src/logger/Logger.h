#ifndef PRIMAVERA_CONCURRENTE_LOGGER_H
#define PRIMAVERA_CONCURRENTE_LOGGER_H

#define LOG_FILE "log.txt"


#include "../comunication/flowers/FlowerReceiver.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../concurrency/Runnable.h"

class Logger: public Runnable {
private:
    FlowerReceiver receiver;
    WriteOnlyFile logFile;

    void log(const FlowerTransaction& transaction);
    void log(const FlowerList& flowers);

public:
    static void sendTransaction(const FlowerTransaction& transaction);

    Logger();

    ~Logger() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_LOGGER_H
