

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

    void receiveTransactions();
    void showStatistics();

public:
    static void sendTransaction(const FlowerTransaction& transaction);

    Statistics();

    ~Statistics() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICS_H
