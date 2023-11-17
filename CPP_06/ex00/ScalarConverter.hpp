#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        ScalarConverter& operator=(const ScalarConverter& other);

    static void convert(const std::string& input);
};

#endif

#endif