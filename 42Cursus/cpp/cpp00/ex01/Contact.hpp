#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	public:

	Contact(); //Constructeur
	~Contact() //Destructeur
	{
	}

	int		add_first_name(void);
	int		add_last_name(void);
	int		add_nickname(void);
	int		add_phone_number(void);
	int		add_darkest_secret(void);

	int			ret_len(int nb) const;
	std::string	ret_string(int nb) const;

	void	print_all_value(int nb) const;

	private:

	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
};

#endif
