#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

class Data
{
	public:
		~Data();
		Data(Data &data);
		Data &operator=(Data &data);
		Data(uintptr_t value);
		uintptr_t	get_value() const;

	private:
		Data();
		uintptr_t	_value;
};

#endif