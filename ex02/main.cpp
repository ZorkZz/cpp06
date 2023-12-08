#include "Base.hpp"

int	main(void)
{
	Base	*a;

	a = generate();
	identify(a);
	identify(*a);
	delete(a);
}