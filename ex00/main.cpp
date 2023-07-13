#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
        {
            std::cout << "wrong count of arg" << std::endl;
            return 1;
        }
        std::string str = av[1];
        ScalarConverter converter;

        converter.convert(str);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
