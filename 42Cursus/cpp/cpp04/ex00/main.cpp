#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		Animal	animal;
		Dog		dog;
		Cat		cat;
		Cat		cat2 = cat;

		std::cout << std::endl;
		animal.makeSound();
		std::cout << std::endl;
		dog.makeSound();
		std::cout << std::endl;
		cat.makeSound();
		std::cout << std::endl;
		cat2.makeSound();
		std::cout << std::endl;
	}
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout<<std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}
	return 0;
}
