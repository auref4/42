#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

void	search_contact(PhoneBook phonebook)
{
	int	nb;

	phonebook.print_header();
	std::cout<<"                    - SEARCH -                     "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"   ----------------------------------------------  "<<std::endl;
	for (int i = 1; i < 9; i++)
	{
		nb = 0;
		std::cout<<"   |        "<<i<<".";
		nb++;
		phonebook.print_value(i, nb);
		nb++;
		phonebook.print_value(i, nb);
		nb++;
		phonebook.print_value(i, nb);
		std::cout<<"|"<<std::endl;
	}
	std::cout<<"   ----------------------------------------------  "<<std::endl;
}

void	add_contact(PhoneBook &phonebook)
{
	Contact	contact = Contact();

	phonebook.print_set_first_name(contact);
	phonebook.print_set_last_name(contact);
	phonebook.print_set_nickname(contact);
	phonebook.print_set_phone_number(contact);
	phonebook.print_set_darkest_secret(contact);
	phonebook.contact_to_phonebook(contact);
}

int	main(void)
{
	PhoneBook	phonebook = PhoneBook();
	std::string	str = "";

	for (;;)
	{
		phonebook.print_header();
		std::cout<<"                 Select an option :                "<<std::endl;
		std::cout<<std::endl;
		std::cout<<"                SEARCH | ADD | EXIT"               <<std::endl;
		std::cout<<std::endl;
		std::cin>>str;
		if (str == "EXIT")
		{
			system("clear");
			std::cout<<std::endl;
			std::cout<<"                        BYE...                     "<<std::endl;
			std::cout<<std::endl;
			break ;
		}
		if (str == "ADD")
			add_contact(phonebook);
		if (str == "SEARCH")
			search_contact(phonebook);
	}
	return (0);
}
