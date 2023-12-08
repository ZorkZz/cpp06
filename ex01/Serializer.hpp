#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
	private:
		~Serializer();

	public:
		Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data	*deserialize(uintptr_t raw);

};

#endif
