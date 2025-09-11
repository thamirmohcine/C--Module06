#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){ return *this; }

ScalarConverter::~ScalarConverter(){}
/*___________________________________________PARSERS_________________________________________________*/


static int is_special(const std::string input , int& var, int check){
    if (input == "nan" || input == "-inf" || input == "+inf" \
    || input == "nanf" || input == "-inff" || input == "+inff") var = SPECIAL; return 0;
}

static int is_character(const std::string input, int& var, int check){
    if ( isascii(input.at(1)) && input.size() == 3 && (input.at(2) == input.at(0) == '\'')) var = CHAR;
    return 0;
}
static int is_integer(const std::string input, int& var, int check){
    size_t i = 0;
    int floating_point = 0;
    if (input.size() > 1 && input[0] == '0') var = ERROR; return ;
    if (input[0] == '-' || input[0] == '+') i++;
    while (i < input.size() &&  (isdigit(input[i] || (input[i] == '.') && floating_point++))){
        if (check == 1  && floating_point <= 1) i++;
        else if ((check == 1  && floating_point > 1)) var = ERROR; return 0;
        i++;
    }
    if (i == input.size()) var = INTEGER; return 1;
    return 0;
}


static int is_float(const std::string input, int& var, int check){
    if (is_integer(input.substr(0, input.size() - 1), var, 1) && input[input.size() - 1] == 'f' && var != ERROR) var = FLOAT_NUMBER;
    return 0;
}

static int is_double(const std::string input, int& var, int check){
    if (is_integer(input.substr(0, input.size() - 1), var, 1) && input[input.size() - 1] && var != ERROR) var = DOBUBLE_NUMBER;
    return 0;
}


/*_________________________________________PRINTERS_______________________________________*/

void imposible(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" <<  std::endl;
}

void is_special(const std::string input){
    std::string value;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input.find('f') != std::string::npos) value = input + 'f';
    std::cout << "float: " << value << std::endl;
    if (input.find('f') != std::string::npos) value = input.substr(0, input.size() - 1);
    std::cout << "double: " << value << std::endl;
}

void printTypeChar(const std::string input, int& var){
    if (isprint(input[0]))  std::cout << "char: " << input << std::endl;
    else if (!isprint(input[0])) std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(input[0])<<  "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(input[0]) <<  std::endl;
}

void printTypeInt(const std::string input, int& var){
    std::stringstream os(input);
    size_t i  = 0;
    os >> i;
    if (i < std::numeric_limits<long>::min() || i > std::numeric_limits<long>::max()) return imposible();
    if (i < 0 || i > 255) std::cout << "char: impossible" << std::endl;
    else if (isprint(i))  std::cout << "char: " << static_cast<char>(i) << std::endl;
    else if (!isprint(i)) std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) <<  "float: " << static_cast<float>(i)<< "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(i) <<  std::endl;
}

void printTypeFloat(const std::string input, int& var){
    std::stringstream os(input);
    double i  = 0;
    os >> i;
    if (i < std::numeric_limits<float>::min() || i > std::numeric_limits<float>::max()) return imposible();
    if (i < 0 || i > 255) std::cout << "char: impossible" << std::endl;
    else if (isprint(i))  std::cout << "char: " << static_cast<char>(i) << std::endl;
    else if (!isprint(i)) std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << i <<  "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(i) << std::endl;
}

void printTypeDouble(const std::string input, int& var){
    std::stringstream os(input);
    long double i  = 0;
    os >> i;
    if (i < std::numeric_limits<double>::min() || i > std::numeric_limits<double>::max()) return imposible();
    if (i < 0 || i > 255) std::cout << "char: impossible" << std::endl;
    else if (isprint(i))  std::cout << "char: " << static_cast<char>(i) << std::endl;
    else if (!isprint(i)) std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << "float: " << static_cast<float>(i) << std::fixed << std::setprecision(1) << "f" << std::endl;
    std::cout << "double: "<< i << std::fixed << std::setprecision(1) << std::endl;
}

void ScalarConverter::convert(const std::string input){
    int i = NONE;
    if (input.empty()) return imposible();
    detectType parsetable[5];
    parsetable[0] = &is_character;
    parsetable[1] = &is_integer;
    parsetable[2] = &is_float;
    parsetable[3] = &is_double;

}

/* Single non-digit char → "a", "."

Integer → "42", "-123"

Float → "42.0f", "-3.14f", "0.0f"

Double → "42.0", "-3.14", "0.0"

Special → "nan", "nanf", "+inf", "-inf", "+inff", "-inff"
*/