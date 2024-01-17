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

void	ScalarConverter::identify_type()
{
	int		i;
	bool	is_d = false;
	bool	is_f = false;

	for (i = 0; i < (int)_str_base.length(); i++)
	{
		if (_str_base[i] == 'f')
			is_f = true;
		if (_str_base[i] == ',' || _str_base[i] == '.')
			is_d = true;
	}
	if (i == 1 && (i < '0' || i > '9'))
	{
		convert_char();
		convert_double();
		convert_float();
		convert_int();
	}
	else if (i >= 1 && !is_d && !is_f)
	{
		convert_int();
		convert_double();
		convert_float();
		convert_char();
	}
	else if (i > 1 && is_f)
	{
		convert_float();
		convert_double();
		convert_int();
		convert_char();
	}
	else if (i > 1 && !is_f)
	{
		convert_double();
		convert_float();
		convert_int();
		convert_char();
	}
}

void	ScalarConverter::convert_double()
{
	if (_str_base.size() == 1 && !std::isdigit(_str_base[0]))
	{
		_number_double = static_cast<double>(_str_base[0]);
		_double_str << "double: " << _number_double;
	}
	else
	{
		try
		{
			_number_double = std::strtod(_str_base.c_str(), NULL);
			_double_str << "double: " << _number_double;
		}
		catch (const std::invalid_argument &e)
		{
			_double_str << "double: invalid conversion";
		}
		catch (const std::out_of_range &e)
		{
			_double_str << "double: invalid conversion";
		}
	}
}

void	ScalarConverter::convert_float()
{
	if (_str_base.size() == 1 && !std::isdigit(_str_base[0]))
	{
		_number_float = static_cast<float>(_str_base[0]);
		_float_str << "float: " << _number_float;
	}
	else
	{
		try
		{
			_number_float = std::strtod(_str_base.c_str(), NULL);
			_float_str << "float: " << _number_float;
		}
		catch (const std::invalid_argument &e)
		{
			_float_str << "float: invalid conversion";
		}
		catch (const std::out_of_range &e)
		{
			_float_str << "float: invalid conversion";
		}
	}
}

void	ScalarConverter::convert_int()
{
	if (_str_base == "-2147483648")
	{
		_number_int = -2147483648;
		_int_str << "int: " << _number_int;
		return ;
	}
	if (_str_base == "2147483647")
	{
		_number_int = 2147483647;
		_int_str << "int: " << _number_int;
		return ;
	}
	if (_str_base.size() == 1 && !std::isdigit(_str_base[0]))
	{
		_number_int = static_cast<float>(_str_base[0]);
	}
	else
	{
		try
		{
			_number_int = std::strtod(_str_base.c_str(), NULL);
		}
		catch (const std::invalid_argument &e)
		{
			_int_str << "int: invalid conversion";
			return ;
		}
		catch (const std::out_of_range &e)
		{
			_int_str << "int: invalid conversion";
			return ;
		}
	}
	if (_number_int == 2147483647 || _number_int == -2147483648)
		_int_str << "int: overflow";
	else
		_int_str << "char: " << _number_int;
}

void	ScalarConverter::convert_char()
{
	if (_str_base.size() == 1 && !std::isdigit(_str_base[0]))
	{
		_number_char = static_cast<char>(_str_base[0]);
	}
	else
	{
		try
		{
			_number_char = std::strtod(_str_base.c_str(), NULL);
		}
		catch (const std::invalid_argument &e)
		{
			_char_str << "char: invalid conversion";
			return ;
		}
		catch (const std::out_of_range &e)
		{
			_char_str << "char: invalid conversion";
			return ;
		}
	}
	if (_number_char < 32 || _number_char > 126)
		_char_str << "char: non displayable";
	else
		_char_str << "char: " << _number_char;
}

void	ScalarConverter::convert()
{
	
	std::stringstream	result;

	identify_type();
	result << _char_str.str() << "\n" << _int_str.str() << "\n" << _float_str.str() << "\n" << _double_str.str();
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
