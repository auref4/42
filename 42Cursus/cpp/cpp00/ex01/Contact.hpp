#ifndef	CONTACT
#define	CONTACT

#include <iostream>
#include <string>

class	Contact
{
	public:

	Contact(); //Constructeur
	void	add_first_name(std::string str);
	void	add_last_name(std::string str);
	void	add_nickname(std::string str);
	void	add_phone_number(std::string str);
	void	add_darkest_secret(std::string str);

	private:

	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
};

#endif
