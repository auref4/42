#include "Serializer.hpp"

//CONSTRUCTOR

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

//DESTRUCTOR

Serializer::~Serializer()
{
}

//OPERATOR

Serializer&	Serializer::operator=(Serializer const &rhs)
{
	(void) rhs;
	return *this;
}

//MEMBER FUNCTIONS

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return	reinterpret_cast<Data*>(raw);
}
