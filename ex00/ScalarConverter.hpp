#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>


enum input_case {
    NONE,
    CHAR,
    INTEGER,
    SPECIAL_DOUBLE,
    SPECIAL_FLOAT,
    FLOAT_NUMBER,
    DOUBLE_NUMBER,
    ERROR
};

typedef int (*detectType) (const std::string, int& var, int check) ;
typedef void (*PrintTypes) (const std::string input, int& var);

class ScalarConverter{

    public:
        static void convert(const std::string input);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};


#endif