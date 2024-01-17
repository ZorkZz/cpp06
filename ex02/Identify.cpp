#include "Base.hpp"

Base	*generate()
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	if (c == 'A')
		return (new A);
	else if (c == 'B')
		return (new B);
	return (new C);
}

void	identify(Base *base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "p: C" << std::endl;
}

void	identify(Base &base)
{
	try
	{
		Base	&_base = dynamic_cast<A&>(base);
		(void) _base;
		std::cout << "r: A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			Base	&_base = dynamic_cast<B&>(base);
			(void) _base;
			std::cout << "r: B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				Base	&_base = dynamic_cast<C&>(base);
				(void) _base;
				std::cout << "r: C" << std::endl;
			}
			catch(std::exception &e)
			{
				std::cout << "Error: identification fail" << std::endl;
			}
		}
	}
}