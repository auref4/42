#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

int	search_contact(PhoneBook &phonebook)
{
	int			nb;
	std::string	str;

	phonebook.print_header();
	std::cout<<"                    - SEARCH -                     "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"   ---------------------------------------------   "<<std::endl;
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
		std::cout<<"   ---------------------------------------------   "<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"chooses a number to display the corresponding contact"<<std::endl;
	std::cout<<"or choose HOME to go home."<<std::endl;
	std::cout<<std::endl;
	while (std::cin.eof() == false)
	{
		std::cin>>str;
		if (str == "HOME")
			return (1);
	}
	return (0);
}

int	add_contact(PhoneBook &phonebook)
{
	Contact	contact = Contact();

	phonebook.print_set_first_name(contact);
	phonebook.print_set_last_name(contact);
	phonebook.print_set_nickname(contact);
	phonebook.print_set_phone_number(contact);
	phonebook.print_set_darkest_secret(contact);
	phonebook.contact_to_phonebook(contact);
	return (1);
}

int	main(void)
{
	PhoneBook	phonebook = PhoneBook();
	std::string	str = "";

	while (std::cin.eof() == false)
	{
		phonebook.print_header();
		std::cout<<"                 Select an option :                "<<std::endl;
		std::cout<<std::endl;
		std::cout<<"                SEARCH | ADD | EXIT"               <<std::endl;
		std::cout<<std::endl;
		std::cin>>str;
		if (str == "EXIT")
			break ;
		if (str == "ADD")
			add_contact(phonebook);
		if (str == "SEARCH")
			search_contact(phonebook);
	}
	system("clear");
	std::cout<<std::endl;
	std::cout<<"                        BYE...                     "<<std::endl;
	std::cout<<std::endl;
	return (0);
}
