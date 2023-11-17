#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>

class BitcoinExchange{
    private:
        std::map<unsigned int, float> _data;
        int                           _error;
        BitcoinExchange(void);
        void                          ft_error(std::string str);
        bool checkLeapYear(unsigned int year);
        unsigned int dateToUnsigned(std::string date);
        unsigned int toDay(unsigned int year, unsigned int month, unsigned int day);
        
    public:
        void displayResult(std::ifstream& inputfile);        
        BitcoinExchange(std::ifstream& datafile);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange(void);
        BitcoinExchange& operator = (const BitcoinExchange& rhs);
        int                           getError(void);

        void displayMap(void);
};


#endif