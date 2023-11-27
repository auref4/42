#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook = PhoneBook();
	std::string	str = NULL;

	for (;;)
	{
		std::cout<<"Welcome to our PhoneBook, please choose between SEARCH, ADD and EXIT"<<std:endl:
		std::cin>>str;
		if (str == "EXIT")
			break ;
		if (str == "ADD")
			add_contact(phonebook);
		if (str == "SEARCH")
			search_contact(phonebook);
	}
	return (0);
}
