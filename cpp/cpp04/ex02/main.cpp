#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	int	i = 0;
	Animal*	animals[100];

	while (i < 50)
	{
		animals[i] = new Dog();
		i++;
	}
	while (i < 100)
	{
		animals[i] = new Cat();
		i++;
	}
	std::cout << std::endl;
	std::cout << "All animals are initialized" << std::endl;
	std::cout << std::endl;
	i = 0;
	while (i < 100)
	{
		delete animals[i];
		i++;
	}
	std::cout << std::endl;
	std::cout << "All animals are deleted" << std::endl;
	std::cout << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		Dog	dog_1;
		Dog	dog_2;

		std::cout << std::endl;
		dog_2 = dog_1;
		std::cout << std::endl;
		Dog	dog_3(dog_2);
		std::cout << std::endl;

	}
	std::cout << std::endl;
	{
		//Animal animal;

		//animal.makeSound();
	}
	return 0;
}
