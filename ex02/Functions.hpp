#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <exception>
#include <typeinfo>
#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif