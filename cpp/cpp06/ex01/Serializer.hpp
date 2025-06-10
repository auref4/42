#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct	Data
{
	int			nb;
	std::string	str;
};

class	Serializer
{
	public :

	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);

	private :

	Serializer();										//CANONICAL
	Serializer(Serializer const &src);					//CANONICAL
	~Serializer();										//CANONICAL

	Serializer&	operator=(Serializer const &rhs);		//CANONICAL
};

#endif
