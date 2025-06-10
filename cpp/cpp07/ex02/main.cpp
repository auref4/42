#include "Array.hpp"

int	main(int, char**)
{
	Array<int>			numbers(44);
	Array<std::string>	strings(12);
	std::string			list[12] =
						{
							"je", "fais", "un", "petit", "test",
							"pour", "voir", "si", "tout", "fonctionne",
							"correctement", "!"
						};

	std::cout << std::endl;
	std::cout << "TEST 1 :" << std::endl;
	try
	{
		Array<int>	void_array;

		std::cout << "size = " << void_array.size() << std::endl;
		std::cout << void_array[0] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 2 :" << std::endl;
	for (int i = 0; i < 44; i++)
		numbers[i] = i;
	for (int i = 0; i < 44; i++)
		std::cout << numbers[i] << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 3 :" << std::endl;
	for (int i = 0; i < 12; i++)
		strings[i] = list[i];
	for (int i = 0; i < 12; i++)
		std::cout << strings[i] << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 4 :" << std::endl;
	Array<std::string>	strings2 = strings;
	for (int i = 0; i < 12; i++)
		std::cout << strings[i] << std::endl;
	std::cout << "Address strings : " << &strings << std::endl;
	std::cout << "Address strings2 : " << &strings2 << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 5 :" << std::endl;
	Array<std::string>	strings3(strings);
	for (int i = 0; i < 12; i++)
		std::cout << strings[i] << std::endl;
	std::cout << "Address strings : " << &strings << std::endl;
	std::cout << "Address strings3 : " << &strings3 << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 6 :" << std::endl;
	try
	{
		Array<int>	test(4);

		for (int i = 0; i < 4; i++)
			test[i] = i;
		for (int i = 0; i < 44; i++)
			std::cout << test[i] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
