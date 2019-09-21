#ifndef PRIMAVERA_CONCURRENTE_LOGGER_H
#define PRIMAVERA_CONCURRENTE_LOGGER_H

#define LOG_FILE "log.txt"


#include "../comunication/flowers/FlowerReceiver.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../concurrency/process/Runnable.h"

class Logger: public Runnable {
private:
    FlowerReceiver receiver;
    WriteOnlyFile logFile;

    /**
     * Log the transaction.
     */
    void log(const FlowerTransaction& transaction);

    /**
     * Create a log of the flowers.
     */
    std::string log(const FlowerList& flowers);

    /**
    * Log dispatch note.
    */
    void logDispatchNote(const FlowerTransaction& transaction);

public:
    /**
     * Send a transaction to be logged.
     */
    static void sendTransaction(const FlowerTransaction& transaction);

    /**
     * Send a dispatch note to be logged.
     */
    static void sendDispatchNote(const FlowerTransaction& transaction);

    /**
     * Constructor.
     */
    Logger();

    /**
     * Destructor.
     */
    ~Logger() override;

    /**
     * Log pending transactions.
     */
    void receiveData(Data data) override;

    /**
     * Get name.
     */
    std::string name() override;

};


#endif //PRIMAVERA_CONCURRENTE_LOGGER_H
