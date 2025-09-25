#include "Functions.hpp"

int main(){
    std::cout << "=== Testing Valid cases ===" << std::endl;
    for (int i(0);i < 6; i++){
        Base *b = generate();
        std::cout << "Pointer Version : " ;
        identify(b);
        std::cout << "Rference Version : " ;
        identify(*b);
        delete b;
        std::cout << "_____________________\n";
    }
    std::cout << "=== Testing Uknown case ===" << std::endl;
    Base *base = new Base();
    std::cout << "(Uknown) Pointer Version : " ;
    identify(base);
    std::cout << "(Uknown) Rference Version : " ;
    identify(*base);
    delete base;
    
}