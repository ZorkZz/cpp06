#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <cmath>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const &ScalarConverter);
		ScalarConverter &operator=(ScalarConverter const &ScalarConverter);
		~ScalarConverter();
		std::string	get_print() const;
		void		convert();

	private:
		std::string	_str_base;
		int			_number_int;
		float		_number_float;
		double		_number_double;
		char		_number_char;
		std::string	_print;
};

std::ostream    &operator << (std::ostream &os, const ScalarConverter &scalar);

#endif