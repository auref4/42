#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class	PhoneBook
{
	public:

	PhoneBook(); //Constructeur

	void	print_header(void);
	void	print_set_first_name(Contact &contact);
	void	print_set_last_name(Contact &contact);
	void	print_set_nickname(Contact &contact);
	void	print_set_phone_number(Contact &contact);
	void	print_set_darkest_secret(Contact &contact);

	void	print_value(int index, int nb);

	void	contact_to_phonebook(Contact contact);

	private:

	int			m_i;
	std::string	m_str;
	Contact		m_contact[8];
};

#endif
