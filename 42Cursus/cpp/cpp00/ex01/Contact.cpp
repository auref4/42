#include "Contact.hpp"

Contact::Contact() : m_first_name(NULL), m_last_name(NULL), m_nickname(NULL),
m_phone_number(0), m_darkest_secret (NULL)
{
}

void	Contact::add_first_name(std::string str)
{
	m_first_name = str;
	str = NULL;
}

void	Contact::add_last_name(std::string str)
{
	m_last_name = str;
	str = NULL;
}

void	Contact::add_nickname(std::string str)
{
	m_nickname = str;
	str = NULL;
}

void	Contact::add_phone_number(std::string str)
{
	m_phone_number = nb;
	nb = 0;
}

void	Contact::add_darkest_secret(std::string str)
{
	m_darkest_secret = str;
	str = NULL;
}

