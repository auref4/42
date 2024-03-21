#ifndef	CHARACTER_HPP
#define	CHARACTER_HPP

#include "ICharacter.hpp"

class	Character : public ICharacter
{
	public:

	Character();									//CANONICAL
	Character(std::string const name);
	Character(Character const &src);				//CANONICAL
	~Character();									//CANONICAL

	Character&	operator=(Character const &rhs);	//CANONICAL

	std::string const	&getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	private :

	std::string	m_name;
	AMateria	*m_items[4];
};

#endif
