#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(std::ifstream& datafile){
    std::string line, date= "";
    float rate;
    unsigned int converted_date;
    size_t pos;
        
    std::getline(datafile, line);
    if (line.empty() || line != "date,exchange_rate"){
        ft_error("Error: Wrong datafile");
        return;
    }
    line.clear();
    while (std::getline(datafile, line)){
        if (line.empty() == true){
            ft_error("Error: data file not correctly formated.");
            return ;
        }
        pos = line.find(',');
        if (pos == std::string::npos || pos != 10){
            ft_error("Error: data file not correctly formated.");
            return ;
        }
        else{
            converted_date = dateToUnsigned(line.substr(0, pos));
            if (converted_date == 1){
                ft_error("Error: Wrong date: " + line.substr(0, 10));
                return ;
            }
            rate = std::atof(line.c_str() + pos + 1);
            if (rate > std::numeric_limits<float>::max() || rate < 0){
                ft_error("Error: Wrong rate on data file.");
                return ;
            }
            _data.insert(std::make_pair(converted_date, rate));
        }
        line.clear();
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs){
    if (this != &rhs){
        this->_data = rhs._data;
        this->_error = rhs._error;
    }
    return (*this);
}

void    BitcoinExchange::ft_error(std::string str){
    std::cout << str << std::endl;
    _error = 1;
}

unsigned int BitcoinExchange::dateToUnsigned(std::string date){
    unsigned int year, month, day;
    unsigned int february = 28;
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (1);
    
    for (int i = 0; i < 10; i++)
    {
        if ((i == 4 || i == 7))
        {
            if (date[i] != '-')
                return (0);
            else
                continue;
        }
        if (!(std::isdigit(date[i])))
            return (1);
    }

    year = std::atoi(date.c_str());
    month = std::atoi(date.c_str() + 5);
    day = std::atoi(date.c_str() + 8);
    if (checkLeapYear(year + 1) == true)
        february = 29;
    unsigned int tab[] = {31, february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year < 1000 || month > 12 || day > tab[month - 1])
        return (1);
    return (toDay(year, month, day));
    
}

int BitcoinExchange::getError(void){
    return (_error);
}

unsigned int BitcoinExchange::toDay(unsigned int year, unsigned int month, unsigned int day){
    unsigned int additionnal_days = 0;
    unsigned int month_to_days = 0;
    unsigned int i;
    unsigned int february = 28;
    if (checkLeapYear(year + 1) == true)
        february = 29;
    unsigned int tab[] = {31, february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (i  = 1000; i < year; i += 4){
        if (checkLeapYear(i) == true)
            additionnal_days++;
    }

    for (i = 0; i < month - 1; i++)
        month_to_days += tab[i];
    return ((year * 365) + month_to_days + day + additionnal_days);
}


bool BitcoinExchange::checkLeapYear(unsigned int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return (true);
    return (false);
}

void BitcoinExchange::displayMap(void){
    std::map<unsigned int, float>::iterator iter;

    for (iter = _data.begin(); iter != _data.end(); ++iter){
        std::cout << "Date: " << iter->first << "    Exchange rate: " << iter->second << std::endl;
    }
}

void BitcoinExchange::displayResult(std::ifstream& inputfile){
    std::string line = "";
    size_t pos;

    int err;
    float value;
    std::map<unsigned int, float>::iterator iter;
    unsigned int date_converted;
    unsigned int minimal_date = dateToUnsigned("2009-01-02");
    
    std::getline(inputfile, line);
    while (std::getline(inputfile, line)){
        if (line.empty())
            continue;
        err = 0;
        pos = line.find('|');
        if (pos == std::string::npos){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        pos = line.find(' ');
        date_converted = dateToUnsigned(line.substr(0, pos));
        if (date_converted == 1){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (date_converted < minimal_date){
            std::cout << "Error: too old date => " << line.substr(0, 10) << std::endl;
            continue;
        }
        for (iter = _data.begin(); iter != _data.end() && iter->first < date_converted; ++iter){}
        --iter;
        if ((line.length() < 14 ||  line[10] != ' ')){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        size_t pos_point = line.find('.');
        for (size_t i = 14; i < line.length(); i++){
            if (!std::isdigit(line[i]) && i != pos_point){
            std::cout << "Error: bad input => " << line << std::endl;
            err = 1;
            break;
            }
        }
        if (err == 1)
            continue;
        value = std::atof(line.c_str() + 13);
        if (value > 1000){
            std::cout << "Error: too large number: " << value << std::endl;
            continue;
        }
        else if(value < 0){
            std::cout << "Error: not a positive number" << std::endl;
        }

        std::cout << line.substr(0, 10) << " => " << value << " = " << value * iter->second << std::endl;

    }
}
