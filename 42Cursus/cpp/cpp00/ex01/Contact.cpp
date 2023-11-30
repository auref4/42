#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

Contact::Contact() : m_first_name(""), m_last_name(""), m_nickname(""),
m_phone_number(""), m_darkest_secret ("")
{
}

int	Contact::add_first_name(void)
{
	while (std::cin.eof() == false)
	{
		std::cin>>m_first_name;
		if (!m_first_name.empty())
			return (1);
	}
	return (0);
}

int	Contact::add_last_name(void)
{
	while (std::cin.eof() == false)
	{
		std::cin>>m_last_name;
		if (!m_last_name.empty())
			return (1);
	}
	return (0);
}

int	Contact::add_nickname(void)
{
	while (std::cin.eof() == false)
	{
		std::cin>>m_nickname;
		if (!m_nickname.empty())
			return (1);
	}
	return (0);
}

int	Contact::add_phone_number(void)
{
	unsigned int	i;
	PhoneBook		phonebook = PhoneBook();

	while (std::cin.eof() == false)
	{
		std::cin>>m_phone_number;
		if (!m_phone_number.empty())
			for (i = 0; std::isdigit(m_phone_number[i]); i++);
		if (i == m_phone_number.size())
					return (1);
		else
		{
			phonebook.print_header();
			std::cout<<"                      - ADD -                      "<<std::endl;
			std::cout<<std::endl;
			std::cout<<"                 Your phone number :               "<<std::endl;
			std::cout<<std::endl;
			std::cout<<"       !try again, only digit are required!        "<<std::endl;
			std::cout<<std::endl;
		}
	}
	return (0);
}

int	Contact::add_darkest_secret(void)
{
	while (std::cin.eof() == false)
	{
		std::cin>>m_darkest_secret;
		if (!m_darkest_secret.empty())
			return (1);
	}
	return (0);
}

int		Contact::ret_len(int nb) const
{
	int	len = 0;

	if (nb == 1)
		if (!m_first_name.empty())
			len = m_first_name.size();
	if (nb == 2)
		if (!m_last_name.empty())
			len = m_last_name.size();
	if (nb == 3)
		if (!m_nickname.empty())
			len = m_nickname.size();
	return (len);
}

std::string	Contact::ret_string(int nb) const
{
	std::string	str = "";

	if (nb == 1)
		str = m_first_name;
	if (nb == 2)
		str = m_last_name;
	if (nb == 3)
		str = m_nickname;
	return (str);
}

void	Contact::print_all_value(int nb) const
{
	std::cout<<nb<<"."<<std::endl<<std::endl;
	std::cout<<"first name : "<<m_first_name<<std::endl;
	std::cout<<"last name : "<<m_last_name<<std::endl;
	std::cout<<"nickname : "<<m_nickname<<std::endl;
	std::cout<<"phone number : "<<m_phone_number<<std::endl;
	std::cout<<"darkest secret : "<<m_darkest_secret<<std::endl;
}
