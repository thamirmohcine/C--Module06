#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){ return *this; }

ScalarConverter::~ScalarConverter(){}
/*___________________________________________PARSERS_________________________________________________*/


static int is_special(const std::string input , int& var, int check){
    if (input == "nan" || input == "-inf" || input == "+inf" ) {var = SPECIAL_FLOAT; return 1;}
    else if (input == "nanf" || input == "-inff" || input == "+inff") {var = SPECIAL_DOUBLE; return 1;}
    return 0;
}

static int is_character(const std::string input, int& var, int check){
    if ( input.size() == 3 &&  (input.front() == '\'' && input.back() == '\''))
    {
        char char_value = input[1];
        isascii(char_value) ;
        var = CHAR; return 1;
    }
    return 0;
}


static int is_integer(const std::string input, int& var, int check){
    size_t i = 0;
    int floating_point = 0;
    if (input[0] == '-' || input[0] == '+') {i++;}
    while (i < input.size() &&  (isdigit(input[i] || ((input[i] == '.') && !floating_point)))){
        if (check == 1  && !floating_point){ floating_point++; i++;}
        else if ((check == 1  && floating_point > 1)) {var = ERROR; return 0;}
        else if(isdigit(input[i])) { i++;}
        else {break;}
    }
    if (i == input.size() && !floating_point && var != ERROR) var = INTEGER; return 1;
    return 0;
}


static int is_float(const std::string input, int& var, int check){
    if (input.size() > 1  && input[input.size() - 1] == 'f'){
        std::string temp_input =  input.substr(0, input.size() - 1);
        int temp_var = NONE;
        if (is_integer(temp_input, temp_var, 1) && temp_var != ERROR) var = FLOAT_NUMBER; return 1;
    }
    return 0;
}

static int is_double(const std::string input, int& var, int check){
    int temp_var = NONE;
    if (is_integer(input, temp_var, 1) && temp_var != ERROR){ var = DOUBLE_NUMBER; return 1;}
    return 0;
}


/*_________________________________________PRINTERS_______________________________________*/

void imposible(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" <<  std::endl;
}

void PrintTypeSpecial(const std::string input, int& var){
    std::string value = input;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (var == SPECIAL_DOUBLE) value = input + 'f';
    std::cout << "float: " << value << std::endl;
    value.erase(value.size() - 1);
    std::cout << "double: " << value << std::endl;
}

void printTypeChar(const std::string input, int& var){
    char char_value = input[1];
    // std::cout << (int)char_value << "  " << input << "\n";
    if (isprint(char_value)) { std::cout << "char: " << input  << std::endl;}
    else { std::cout << "char: Non displayable" << std::endl; }
    std::cout << "int: " << static_cast<int>(char_value) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(char_value)<<  "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(char_value) <<  std::endl;
}

void printTypeInt(const std::string input, int& var){
    std::stringstream os(input);
    long i  = 0;
    os >> i;
    
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) return imposible();
    if (i < 0 || i > 127) std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(i)))  std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else { std::cout << "char: Non displayable" << std::endl; }
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) <<  "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(i) <<  std::endl;
}

void printTypeFloat(const std::string input, int& var){
    std::stringstream os(input);
    double i  = 0;
    os >> i;

    if (i < std::numeric_limits<float>::min() || i > std::numeric_limits<float>::max()) return imposible();
    int int_val = static_cast<int>(i);
    if (i < 0 || i > 127 || static_cast<float>(int_val) != i) std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(int_val)))  std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else { std::cout << "char: Non displayable" << std::endl; }
    if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    else {std::cout << "int: impossible" << std::endl;}
    std::cout << std::fixed << std::setprecision(1) << "float: " << i <<  "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: "<< static_cast<double>(i) << std::endl;
}

void printTypeDouble(const std::string input, int& var){
    std::stringstream os(input);
    long double i  = 0;
    os >> i;

    if (i < std::numeric_limits<double>::min() || i > std::numeric_limits<double>::max()) return imposible();
    int int_val = static_cast<int>(i);
    if (i < 0 || i > 127 || static_cast<double>(int_val) != i) std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(int_val)))  std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else { std::cout << "char: Non displayable" << std::endl;}
    if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    else {std::cout << "int: impossible" << std::endl;}
    std::cout << "float: " << static_cast<float>(i) << std::fixed << std::setprecision(1) << "f" << std::endl;
    std::cout << "double: "<< i << std::fixed << std::setprecision(1) << std::endl;
}



void ScalarConverter::convert(const std::string input){
    int i = NONE;
    if (input.empty()) return imposible();
    detectType parsetable[5];
    parsetable[0] = &is_character;
    parsetable[1] = &is_integer;
    parsetable[2] = &is_special;
    parsetable[3] = &is_float;
    parsetable[4] = &is_double;

    while (i == NONE){ 
        for (int s = 0;s < 5;s++){
            if ((*parsetable[s])(input, i, 0) && i != NONE) { break; }
        }
    }
    PrintTypes PrintTable[7];
    PrintTable[0] = &printTypeChar;
    PrintTable[1] = &printTypeInt;
    PrintTable[2] = &PrintTypeSpecial;
    PrintTable[3] = &PrintTypeSpecial;
    PrintTable[4] = &printTypeFloat;
    PrintTable[5] = &printTypeDouble;
    if (i > 0 && i < 7)
        return (*PrintTable[i-1])(input, i);
    std::cout << "INVALID INPUT .\n";
}

/* Single non-digit char → "a", "."

Integer → "42", "-123"

Float → "42.0f", "-3.14f", "0.0f"

Double → "42.0", "-3.14", "0.0"

Special → "nan", "nanf", "+inf", "-inf", "+inff", "-inff"
*/