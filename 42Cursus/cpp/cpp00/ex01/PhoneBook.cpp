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

void	PhoneBook::print_set_first_name(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your first name :                "<<std::endl;
	std::cout<<std::endl;
	contact.add_first_name();
}

void	PhoneBook::print_set_last_name(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your last name :                 "<<std::endl;
	std::cout<<std::endl;
	contact.add_last_name();
}

void	PhoneBook::print_set_nickname(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                  Your nickname :                  "<<std::endl;
	std::cout<<std::endl;
	contact.add_nickname();
}

void	PhoneBook::print_set_phone_number(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                 Your phone number :               "<<std::endl;
	std::cout<<std::endl;
	contact.add_phone_number();
}

void	PhoneBook::print_set_darkest_secret(Contact &contact) const
{
	print_header();
	std::cout<<"                      - ADD -                      "<<std::endl;
	std::cout<<std::endl;
	std::cout<<"                Your darkest secret :              "<<std::endl;
	std::cout<<std::endl;
	contact.add_darkest_secret();
}

void	PhoneBook::print_value(int index, int nb)
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
void	PhoneBook::contact_to_phonebook(Contact contact)
{
	if (m_i == 8)
		m_i = 0;
	m_contact[m_i] = contact;
	m_i++;
}
