#include "Serializer.hpp"

int	main(void)
{
	Data		data;

	data.nb = 4;
	data.str = "It's just a test";

	std::cout << "BEFORE SERIALIZE/DESERIALIZE :" << std::endl;
	std::cout << "address : " << &data << std::endl;
	std::cout << "nb : " << data.nb << std::endl;
	std::cout << "std : " << data.str << std::endl;
	std::cout << std::endl;
	uintptr_t	uintptr = Serializer::serialize(&data);
	Data*	data2 = Serializer::deserialize(uintptr);
	std::cout << "AFTER SERIALIZE/DESERIALIZE :" << std::endl;
	std::cout << "address : " << data2 << std::endl;
	std::cout << "nb : " << data2->nb << std::endl;
	std::cout << "str : " << data2->str << std::endl;
}
