#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>

class ScalarConverter {
    public:
            ScalarConverter();
            ScalarConverter(const ScalarConverter& src);
            ScalarConverter& operator=(const ScalarConverter& src);
            ~ScalarConverter();
            void convert(std::string &str);
};

#endif