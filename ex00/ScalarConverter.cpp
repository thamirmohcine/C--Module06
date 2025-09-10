#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){ return *this; }

ScalarConverter::~ScalarConverter(){}

static void is_character(const std::string input, int& var){

    if (input.empty()) var = ERROR;
    if (input.size() == 1 && !std::isdigit(input[0])) if (isprint(input[0])) var = PRINTABLE_CHAR; else var = NON_PRINTABLE_CHAR;

}

static void is_integer(const std::string input, int& var){

}

static void is_float(const std::string input, int& var){
    
}

static void is_double(const std::string input, int& var){

}


void ScalarConverter::convert(const std::string input){
    int i = NONE;
    checker parsetable[5];
    parsetable[0] = &is_character;
    parsetable[1] = &is_integer;
    parsetable[2] = &is_float;
    parsetable[3] = &is_double;
    // while (inpu)
}

/* Single non-digit char → "a", "."

Integer → "42", "-123"

Float → "42.0f", "-3.14f", "0.0f"

Double → "42.0", "-3.14", "0.0"

Special → "nan", "nanf", "+inf", "-inf", "+inff", "-inff"
*/