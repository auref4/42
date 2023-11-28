#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstring>

Contact::Contact() : m_first_name(""), m_last_name(""), m_nickname(""),
m_phone_number(""), m_darkest_secret ("")
{
}

void	Contact::add_first_name(std::string str)
{
	m_first_name = str;
	str = "";
}

void	Contact::add_last_name(std::string str)
{
	m_last_name = str;
	str = "";
}

void	Contact::add_nickname(std::string str)
{
	m_nickname = str;
	str = "";
}

void	Contact::add_phone_number(std::string str)
{
	m_phone_number = str;
	str = "";
}

void	Contact::add_darkest_secret(std::string str)
{
	m_darkest_secret = str;
	str = "";
}

int		Contact::ret_len(int nb)
{
	int	len = 0;

	if (nb == 1)
		len = m_first_name.size();
	if (nb == 2)
		len = m_last_name.size();
	if (nb == 3)
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
