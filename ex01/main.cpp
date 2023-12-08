#include "Serializer.hpp"

int	main(void)
{
	Data	data(75);
	std::cout << "serialize: " << Serializer::serialize(&data) << std::endl;

	std::cout << "deserialize: " << Serializer::deserialize(data.get_value()) << std::endl;
}