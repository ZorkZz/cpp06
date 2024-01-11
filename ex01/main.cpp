#include "Serializer.hpp"

int	main(void)
{
	{
		Data		data(18);
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "serialize: " << raw << std::endl;

		std::cout << "deserialize: " << Serializer::deserialize(raw) << std::endl;
		std::cout << "value: " << Serializer::deserialize(raw)->get_value() << std::endl;
	}

	{
		Data		data(27);
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "serialize: " << raw << std::endl;

		std::cout << "deserialize: " << Serializer::deserialize(raw) << std::endl;
		std::cout << "value: " << Serializer::deserialize(raw)->get_value() << std::endl;
	}

	{
		Data		data(696);
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "serialize: " << raw << std::endl;

		std::cout << "deserialize: " << Serializer::deserialize(raw) << std::endl;
		std::cout << "value: " << Serializer::deserialize(raw)->get_value() << std::endl;
	}
}