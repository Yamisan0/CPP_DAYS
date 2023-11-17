#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    if (this != &other) {}
    return *this;
}

bool isValidNumber(const std::string& str)
{
    int nbDot = 0;
    for (size_t i = 0; i < str.size(); ++i) 
    {
        char ch = str[i];
        if (!std::isdigit(ch) && ch != '.' && ch != '+' && ch != '-') 
        {
            return false;
        }
        if (ch == '.')
        {
            nbDot++;
            if (nbDot > 1)
                return false;
        }
    }
    return true;
}

void ScalarConverter::convert(const std::string& input) 
{
    double doubleVal;
    float  floatVal;

    if (input == "nan" || input == "nanf")
        doubleVal = std::numeric_limits<double>::quiet_NaN();
    else if (input == "-inf" || input == "-inff")
        doubleVal = -std::numeric_limits<double>::infinity();
    else if (input == "+inf" || input == "inf" || input == "+inff" || input == "inff")
        doubleVal = std::numeric_limits<double>::infinity();
    else 
    {
        std::string tmp = input;
 
        if (!tmp.empty() && tmp[tmp.size() - 1] == 'f') 
            tmp.erase(tmp.size() - 1);

        if (!isValidNumber(tmp)) 
        {
            std::cout << "Invalid input" << std::endl;
            return;
        }

        std::stringstream ss(input);
        ss >> doubleVal;

        if (ss.fail()) 
        {
            std::cout << "Invalid input" << std::endl;
            return;
        }
    }

    // char
    if (doubleVal < std::numeric_limits<char>::min() || doubleVal > std::numeric_limits<char>::max() || std::isnan(doubleVal) || std::isinf(doubleVal))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(doubleVal)))
        std::cout << "char: '" << static_cast<char>(doubleVal) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // int
    if (doubleVal < std::numeric_limits<int>::min() || doubleVal > std::numeric_limits<int>::max() || std::isnan(doubleVal) || std::isinf(doubleVal))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;

    // float
    floatVal = static_cast<float>(doubleVal);
    std::cout << "float: " << floatVal << (floatVal == static_cast<int>(floatVal) ? ".0f" : "f") << std::endl;

    // double
    std::cout << "double: " << doubleVal << (doubleVal == static_cast<int>(doubleVal) ? ".0" : "") << std::endl;
}