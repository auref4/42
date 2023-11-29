#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class	PhoneBook
{
	public:

	PhoneBook(); //Constructeur

	void	print_header(void) const;
	void	print_set_first_name(Contact &contact) const;
	void	print_set_last_name(Contact &contact) const;
	void	print_set_nickname(Contact &contact) const;
	void	print_set_phone_number(Contact &contact) const;
	void	print_set_darkest_secret(Contact &contact) const;

	void	print_value(int index, int nb);

	void	contact_to_phonebook(Contact contact);

	private:

	int			m_i;
	Contact		m_contact[8];
};

#endif
