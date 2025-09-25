#include "Serializer.hpp"

int main(){
    std::cout << "=== INIT DATA* ===" << std::endl;
    Data *ptr = new Data();
    ptr->charactere = 'a';
    std::cout << ptr->charactere << std::endl;
    ptr->double_ = 42.1337;
    std::cout << ptr->double_ << std::endl;
    ptr->inetegr = 1337;
    std::cout << ptr->inetegr << std::endl;
    ptr->string = "Testing";
    std::cout << ptr->string << std::endl;
    
    std::cout << "=== SERIALIZE DATA* INTO UNITPTR_T  ===" << std::endl;
    uintptr_t int_ptr = Serializer::serialize(ptr);
    std::cout << int_ptr << std::endl;

    std::cout << "=== DESERIALIZE UNITPTR_T BACK INTO DATA* ===" << std::endl;
    ptr = Serializer::deserialize(int_ptr);
    ptr->charactere = 'a';
    std::cout << ptr->charactere << std::endl;
    ptr->double_ = 42.1337;
    std::cout << ptr->double_ << std::endl;
    ptr->inetegr = 1337;
    std::cout << ptr->inetegr << std::endl;
    ptr->string = "Testing";
    std::cout << ptr->string << std::endl;

}