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
	int		print_set_first_name(Contact &contact) const;
	int		print_set_last_name(Contact &contact) const;
	int		print_set_nickname(Contact &contact) const;
	int		print_set_phone_number(Contact &contact) const;
	int		print_set_darkest_secret(Contact &contact) const;

	void	print_search_header_value(PhoneBook phonebook) const;
	void	print_search_value(int index, int nb) const;
	int		print_deep_value(int nb) const;

	void	contact_to_phonebook(Contact contact);

	private:

	int			m_i;
	Contact		m_contact[8];
};

#endif
