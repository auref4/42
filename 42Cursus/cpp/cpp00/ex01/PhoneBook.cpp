#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <stdlib.h>

PhoneBook::PhoneBook() : m_i(0)
{
}

void	PhoneBook::print_header(void) const
{
	system("clear");
	std::cout<<"---------------------------------------------------"<<std::endl;
	std::cout<<"|                    PhoneBook                    |"<<std::endl;
	std::cout<<"---------------------------------------------------"<<std::endl;
	std::cout<<std::endl;
}

int	PhoneBook::print_set_first_name(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your first name :                "<<std::endl;
	std::cout<<std::endl;
	if (contact.add_first_name() == false)
		return (0);
	return (1);
}

int	PhoneBook::print_set_last_name(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your last name :                 "<<std::endl;
	std::cout<<std::endl;
	if (contact.add_last_name() == false)
		return (0);
	return (1);
}

int	PhoneBook::print_set_nickname(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your nickname :                  "<<std::endl;
	std::cout<<std::endl;
	if (contact.add_nickname() == false)
		return (0);
	return (1);
}

int	PhoneBook::print_set_phone_number(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                 Your phone number :               "<<std::endl;
	std::cout<<std::endl;
	if (!contact.add_phone_number())
		return (0);
	return (1);
}

int	PhoneBook::print_set_darkest_secret(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                Your darkest secret :              "<<std::endl;
	std::cout<<std::endl;
	if (!contact.add_darkest_secret())
		return (0);
	return (1);
}

void	PhoneBook::print_search_header_value(PhoneBook phonebook) const
{
	int	nb;

	print_header();
	std::cout<<"                    - SEARCH -                     "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"   ---------------------------------------------   "<<std::endl;
	for (int i = 1; i < 9; i++)
	{
		nb = 0;
		std::cout<<"   |        "<<i<<".";
		nb++;
		phonebook.print_search_value(i, nb);
		nb++;
		phonebook.print_search_value(i, nb);
		nb++;
		phonebook.print_search_value(i, nb);
		std::cout<<"|"<<std::endl;
		std::cout<<"   ---------------------------------------------   "<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"chooses a number to display the corresponding contact"<<std::endl;
	std::cout<<"or choose HOME to go home or BACK to go back."<<std::endl;
	std::cout<<std::endl;
}

void	PhoneBook::print_search_value(int index, int nb) const
{
	int			len = 0;
	int			tmp = 10;
	std::string	str;

	len = m_contact[index - 1].ret_len(nb);
	str = m_contact[index - 1].ret_string(nb);
	tmp = tmp - len;
	std::cout<<"|";
	if (tmp >=0)
	{
		for (int i = 0; i < tmp; i++)
			std::cout<<" ";
		std::cout<<str;
	}
	if (tmp < 0)
	{
		for (int i = 0; i < 9; i++)
			std::cout<<str[i];
		std::cout<<".";
	}
}

int	PhoneBook::print_deep_value(int nb) const
{
	std::string	str;

	print_header();
	std::cout<<std::endl;
	m_contact[nb - 1].print_all_value(nb);
	std::cout<<std::endl;
	std::cout<<"Choose HOME or BACK to go back."<<std::endl;
	std::cout<<std::endl;
	while (std::cin.eof() == false)
	{
		std::cin>>str;
		if (str == "HOME")
			return (0);
		if (str == "BACK")
			return (1);
	}
	return (1);
}

void	PhoneBook::contact_to_phonebook(Contact contact)
{
	if (m_i == 8)
		m_i = 0;

	m_contact[m_i] = contact;
	m_i++;
}
