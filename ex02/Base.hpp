#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base	*generate();
void	identify(Base *base);
void	identify(Base &base);

#endif