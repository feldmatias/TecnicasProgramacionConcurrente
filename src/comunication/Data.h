

#ifndef PRIMAVERA_CONCURRENTE_DATA_H
#define PRIMAVERA_CONCURRENTE_DATA_H


#include <string>

class Data {
private:
    std::string header;
    std::string data;

public:
    /**
     * Create data with header.
     */
    Data(std::string header, std::string data);

    /**
     * Destructor
     */
     ~Data();

     /**
      * Get header.
      */
      std::string getHeader() const;

      /**
       * Get data.
       */
       std::string getData() const;

};


#endif //PRIMAVERA_CONCURRENTE_DATA_H
