#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>


enum input_case {
    NONE,
    PRINTABLE_CHAR,
    NON_PRINTABLE_CHAR,
    INTEGER,
    FLOAT_NUMBER,
    SPECIAL_FLOAT,
    DOBUBLE_NUMBER,
    SPECIAL_DOUBLE,
    ERROR
};

typedef void (*f) (const std::string, int& var) checker;

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