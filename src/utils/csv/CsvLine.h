

#ifndef PRIMAVERA_CONCURRENTE_CSVLINE_H
#define PRIMAVERA_CONCURRENTE_CSVLINE_H


#include <string>
#include <sstream>

class CsvLine {
private:
    std::stringstream line;

public:
    explicit CsvLine();

    explicit CsvLine(const std::string& line);

    ~CsvLine();

    std::string getNext();

    void setNext(const std::string& element);

    std::string getCsv() const;
};


#endif //PRIMAVERA_CONCURRENTE_CSVLINE_H
