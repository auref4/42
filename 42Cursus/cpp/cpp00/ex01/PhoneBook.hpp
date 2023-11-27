#ifndef	PHONEBOOK
#define	PHONEBOOK

#include "Contact.hpp"

class	PhoneBook
{
	public:

	PhoneBook(); //Constructeur
	void	contact_to_phonebook(Contact contact);

	private:

	Contact	m_contact[8];
	int		m_i;
};

#endif
