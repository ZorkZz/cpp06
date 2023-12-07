#include "Convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage: ./a.out arg0" << std::endl;
		return (1);
	}
	ScalarConverter	scalar(av[1]);
	scalar.convert();
	std::cout << scalar << std::endl;
	return (0);
}