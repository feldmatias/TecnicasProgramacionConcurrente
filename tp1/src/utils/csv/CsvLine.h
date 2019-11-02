

#ifndef PRIMAVERA_CONCURRENTE_CSVLINE_H
#define PRIMAVERA_CONCURRENTE_CSVLINE_H


#include <string>
#include <sstream>

class CsvLine {
private:
    std::stringstream line;

public:
    /**
     * Create an empty csv line.
     */
    explicit CsvLine();

    /**
     * Create a csv line.
     */
    explicit CsvLine(const std::string &line);

    /**
     * Destructor.
     */
    ~CsvLine();

    /**
     * Set next element of the csv.
     */
    void setNext(const std::string &element);

    /**
     * Get next element of the csv.
     */
    std::string getNext();

    /**
     * Set next element of the csv.
     */
    void setNext(int element);

    /**
     * Get next element of the csv.
     */
    int getNextNumber();

    /**
     * Get the csv line.
     */
    std::string getCsv() const;
};


#endif //PRIMAVERA_CONCURRENTE_CSVLINE_H
