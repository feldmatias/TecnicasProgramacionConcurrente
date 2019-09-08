

#ifndef PRIMAVERA_CONCURRENTE_STATISTICS_H
#define PRIMAVERA_CONCURRENTE_STATISTICS_H


#include "../comunication/comunicators/StatisticsComunicator.h"
#include "../flower/FlowerTransaction.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../concurrency/Runnable.h"

typedef std::unordered_map<std::string, size_t> StatisticsMap;

class Statistics : public Runnable {
private:
    FlowerReceiver transactionReceiver;
    StatisticsComunicator comunicator;

    StatisticsMap salesBySeller;
    StatisticsMap salesByType;

    /**
     * Receive all transactions made.
     */
    void receiveTransactions();

    /**
     * Show statistics to the user.
     */
    void showStatistics();

public:
    /**
     * Send transaction to statistics.
     */
    static void sendTransaction(const FlowerTransaction& transaction);

    /**
     * Constructor.
     */
    Statistics();

    /**
     * Destructor.
     */
    ~Statistics() override;

    /**
     * Show statistics if were asked.
     */
    void doWork() override;

    /**
     * Stop working.
     */
    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICS_H
