#include "Functions.hpp"

Base * generate(void){
    static bool a = 0;
    if (!a){
        std::srand(static_cast<unsigned int>(std::time(0)));
        a = !a;
    }
    int random_number = std::rand() % 3;
    if (random_number == 1) {return new A();}
    if (random_number == 2) {return new B();}
    return new C();
}

void identify(Base* p){
    if (dynamic_cast<A*>(p)) {std::cout << "A" << std::endl; return ;}
    if (dynamic_cast<B*>(p)) {std::cout << "B" << std::endl; return ;}
    if (dynamic_cast<C*>(p)) {std::cout << "C" << std::endl; return ;}
    std::cout << "Uknown Type" << std::endl;
    return ;
}

void identify(Base& p){
    try{
        A& a_ref = dynamic_cast<A&>(p);
        (void )a_ref;
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast& ){
        try{
            B& b_ref = dynamic_cast<B&>(p);
            (void )b_ref;
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast& ){
            try{
                C& c_ref = dynamic_cast<C&>(p);
                (void )c_ref;
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast& ){
                std::cout << "Uknown Type" << std::endl;
            }
        }
    }
}