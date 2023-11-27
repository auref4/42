#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void	add_contact(void)
{
	Contact	contact = Contact();
	std::string	str = NULL;

	std::cout<<"your first name :"<<std:endl:
	for (;;)
	{
		std::cin>>str;
		if (str)
			break ;
	}
	contact.add_first_name(contact, str);
	std::cout<<"your last name :"<<std:endl:
	for (;;)
	{
		std::cin>>str;
		if (str)
			break ;
	}
	contact.add_last_name(contact, str);
	std::cout<<"your first nickname :"<<std:endl:
	for (;;)
	{
		std::cin>>str;
		if (str)
			break ;
	}
	contact.add_nickname(contact, str);
	std::cout<<"your phone number :"<<std:endl:
	for (;;)
	{
		std::cin>>str;
		if (str)
			break ;
	}
	contact.add_phone_number(contact, str);
	std::cout<<"your darkest secret :"<<std:endl:
	for (;;)
	{
		std::cin>>str;
		if (str)
			break ;
	}
	contact.add_darkest_secret(contact, str);
	phonebook.contact_to_phonebook(contact);
}
