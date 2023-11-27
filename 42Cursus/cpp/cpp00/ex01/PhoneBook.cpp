#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() : m_i(0)
{
}

void	contact_to_phonebook(Contact contact)
{
	if (m_i == 7)
		m_i = 0;
	m_contact[m_i] = contact;
	m_i++;
}
