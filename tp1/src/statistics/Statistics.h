#ifndef PRIMAVERA_CONCURRENTE_STATISTICS_H
#define PRIMAVERA_CONCURRENTE_STATISTICS_H


#include "../flower/FlowerTransaction.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../concurrency/process/Runnable.h"

#define STATISTICS "Statistics"
#define SHOW_STATISTICS "SHOW_STATISTICS"

typedef std::unordered_map<std::string, size_t> StatisticsMap;

class Statistics : public Runnable {
private:
    FlowerReceiver transactionReceiver;

    StatisticsMap salesBySeller;
    StatisticsMap salesByType;

    /**
     * Receive all transactions made.
     */
    void receiveTransaction(const std::string &transactionData);

    /**
     * Show statistics to the user.
     */
    void showStatistics();

public:
    /**
     * Send transaction to statistics.
     */
    static void sendTransaction(const FlowerTransaction &transaction);

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
    void doWork(Data data) override;

    /**
     * Get name.
     */
    std::string name() override;

};


#endif //PRIMAVERA_CONCURRENTE_STATISTICS_H
