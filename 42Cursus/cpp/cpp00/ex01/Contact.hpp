#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	public:

	Contact(); //Constructeur

	void		add_first_name(void);
	void		add_last_name(void);
	void		add_nickname(void);
	void		add_phone_number(void);
	void		add_darkest_secret(void);

	int			ret_len(int nb);
	std::string	ret_string(int nb);

	private:

	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
};

#endif
