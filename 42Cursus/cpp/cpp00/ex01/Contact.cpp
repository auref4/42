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

void	Contact::add_first_name(void)
{
	for (;;)
	{
		std::cin>>m_first_name;
		if (!m_first_name.empty())
			break ;
	}
}

void	Contact::add_last_name(void)
{
	for (;;)
	{
		std::cin>>m_last_name;
		if (!m_last_name.empty())
			break ;
	}
}

void	Contact::add_nickname(void)
{
	for (;;)
	{
		std::cin>>m_nickname;
		if (!m_nickname.empty())
			break ;
	}
}

void	Contact::add_phone_number(void)
{
	unsigned int	i;
	PhoneBook		phonebook = PhoneBook();

	for (;;)
	{
		std::cin>>m_phone_number;
		if (!m_phone_number.empty())
			for (i = 0; std::isdigit(m_phone_number[i]); i++);
		if (i == m_phone_number.size())
					break ;
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
}

void	Contact::add_darkest_secret(void)
{
	for (;;)
	{
		std::cin>>m_darkest_secret;
		if (!m_darkest_secret.empty())
			break ;
	}
}

int		Contact::ret_len(int nb)
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

std::string	Contact::ret_string(int nb)
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
