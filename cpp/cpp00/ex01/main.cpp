#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

int	search_contact(PhoneBook &phonebook)
{
	std::string	str;

	phonebook.print_search_header_value(phonebook);
	while (std::cin.eof() == false)
	{
		std::getline(std::cin, str);
		if (str == "HOME" || str == "BACK")
			return (1);
		else if (str.size() == 1 && str[0] >= '1' && str[0] <= '8')
		{
			if (phonebook.print_deep_value(str[0] - 48) == false)
				return (1);
			else
				phonebook.print_search_header_value(phonebook);
		}
		else
			phonebook.print_search_header_value(phonebook);
	}
	return (0);
}

int	add_contact(PhoneBook &phonebook)
{
	Contact	contact = Contact();

	if (phonebook.print_set_first_name(contact) == false)
		return (0);
	if (phonebook.print_set_last_name(contact) == false)
		return (0);
	if (phonebook.print_set_nickname(contact) == false)
		return (0);
	if (phonebook.print_set_phone_number(contact) == false)
		return (0);
	if (phonebook.print_set_darkest_secret(contact) == false)
		return (0);
	phonebook.contact_to_phonebook(contact);
	return (1);
}

int	main(void)
{
	PhoneBook	phonebook = PhoneBook();
	std::string	str;

	while (std::cin.eof() == false)
	{
		phonebook.print_header();
		std::cout<<"                 Select an option :                "<<std::endl;
		std::cout<<std::endl;
		std::cout<<"                SEARCH | ADD | EXIT"               <<std::endl;
		std::cout<<std::endl;
		std::getline(std::cin, str);
		if (str == "EXIT")
			break ;
		if (str == "ADD")
		{
			if (add_contact(phonebook) == false)
				break ;
		}
		if (str == "SEARCH")
		{
			if (search_contact(phonebook) == false)
				break ;
		}
	}
	system("clear");
	std::cout<<std::endl;
	std::cout<<"                        BYE...                     "<<std::endl;
	std::cout<<std::endl;
	return (0);
}
