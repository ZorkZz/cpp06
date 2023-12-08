#include "Convert.hpp"

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string str): _str_base(str)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &scalar)
{
	if (this != &scalar)
		*this = scalar;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &scalar)
{
	_str_base = scalar._str_base;
	_number_int = scalar._number_int;
	_number_float = scalar._number_float;
	_number_double = scalar._number_double;
	_number_char = scalar._number_char;
	_print = scalar._print;
	return (*this);
}

void	ScalarConverter::convert()
{
	std::stringstream	double_str;
	std::stringstream	float_str;
	std::stringstream	int_str;
	std::stringstream	char_str;
	std::stringstream	result;

	if (_str_base.size() == 1 && !std::isdigit(_str_base[0]))
	{
		_number_double = static_cast<double>(_str_base[0]);
		double_str << "double: " << _number_double << "\n";
	}
	else
	{
		try
		{
			_number_double = std::strtod(_str_base.c_str(), NULL);
			double_str << "double: " << _number_double << "\n";
		}
		catch (const std::invalid_argument &e)
		{
			double_str << "double: invalid conversion" << "\n";
		}
		catch (const std::out_of_range &e)
		{
			double_str << "double: invalid conversion" << "\n";
		}
	}
	float_str << "float: " << static_cast<float>(_number_double) << "f" << "\n";
	if (isinf(_number_double) || isnan(_number_double))
		int_str << "int: invalid conversion" << "\n";
	else
	{
		if (_number_double > std::numeric_limits<int>::max())
			int_str << "int: overflow" << "\n";
		else if (_number_double < -std::numeric_limits<int>::max())
			int_str << "int: underflow" << "\n";
		else
		{
			_number_int = static_cast<int>(_number_double);
			int_str << "int: " << static_cast<int>(_number_double) << "\n";
		}
	}
	if (isinf(_number_double) || isnan(_number_double))
		char_str << "char: invalid conversion" << "\n";
	else
	{
		if (_number_double < 32 || _number_double > 126)
			char_str << "char: non displayable" << "\n";
		else
		{
			_number_char = static_cast<char>(_number_double);
			char_str << "char: " << static_cast<char>(_number_double) << "\n";
		}
	}
	result << char_str.str() << int_str.str() << float_str.str() << double_str.str();
	_print = result.str();
	return;
}

std::string	ScalarConverter::get_print() const
{
	return (this->_print);
}

std::ostream    &operator << (std::ostream &os, const ScalarConverter &scalar)
{
	os << scalar.get_print();
	return (os);
}
