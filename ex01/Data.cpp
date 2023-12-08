#include "Data.hpp"

Data::Data()
{}

Data::~Data()
{}

Data::Data(uintptr_t value): _value(value)
{}

Data::Data(Data &data)
{
	if (this != &data)
		*this = data;
}

Data &Data::operator=(Data &data)
{
	_value = data.get_value();
	return (*this);
}

uintptr_t	Data::get_value() const
{
	return (_value);
}