#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    (void)src;
}
 
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    (void)src;

    return *this;
}

ScalarConverter::~ScalarConverter() {}


static bool    isChar(std::string &str) {
    if (str.length() != 1)
        return false;
    if (str.at(0) < std::numeric_limits<char>::min() || 
       str.at(0) > std::numeric_limits<char>::max() || isdigit(str.at(0)))
       return false;
    return true;
}

static bool    isInt(std::string &str)
{
    size_t i;
    size_t j;
    if (str.at(0) == '-')
        j = 1;
    else
        j = 0;
    for (i = j; i < str.length(); i++)
    {
        if (!isdigit(str.at(i)))
            return false;
    }
    return true;
}

static bool    isFloat(std::string &str)
{
    bool flag = false;

    if (str == "+inff" || str == "-inff" || str == "nanf")
        return true;
    if (str.at(0) == '.' || str.at(str.length() - 1) != 'f')
        return false;
    for (size_t i = 0; i < str.length() - 1; i++)
    {
        if (str.at(i) == '.' && flag) {
            return false;
        }
        else if (str.at(i) == '.') {
            flag = true;
            continue;
        }
        if (!isdigit(str.at(i))) {
            return false;
        }
    }
    return true;
}

static int isDouble(std::string &str)
{
    bool flag = false;

    if (str == "+inf" || str == "-inf" || str == "nan")
        return true;
    if (str.at(0) == '.')
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '.' && flag) {
            return false;
        }
        else if (str.at(i) == '.') {
            flag = true;
            continue;
        }
        if (!isdigit(str.at(i))) {
            return false;
        }
    }
    return true;  
}

static int checkType(std::string &str)
{
    if (isChar(str))
        return 1;
    if (isInt(str))
        return 2;
    if (isFloat(str))
        return 3;
    if (isDouble(str))
        return 4;
    return -1;
}

void    convToChar(std::string &str)
{
    std::cout << "char: " << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void    convToInt(std::string &str)
{
    int i;
    std::istringstream iss(str);
    iss >> i;

    if (!(isprint(i))) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "float: " << static_cast<double>(i) << ".0" << std::endl;
}

void    convToDouble(std::string &str)
{
    float i;
    std::istringstream iss(str);
    iss >> i;

    if (!isprint(static_cast<int>(i))) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << "float: " << i << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void    convToFloat(std::string &str)
{
    std::string str1 = str.substr(0, str.length() - 1);
    
    float i;
    std::istringstream iss(str1);
    iss >> i;

    if (!isprint(static_cast<int>(i))) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << "float: " << i << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convert(std::string &str) {
    
    void (*get_type[4])(std::string &str){&convToChar, &convToInt, &convToFloat, &convToDouble};
    int types[] = {1,2,3,4};

    for (int i = 0; i < 4; i++)
    {
        if (types[i] == checkType(str)) {
            get_type[i](str);
            return ;
        }
    }
    throw std::runtime_error("Uknown Type");
}

