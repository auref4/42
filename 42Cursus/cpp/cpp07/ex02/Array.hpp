#ifndef	ARRAY_HPP
#define	ARRAY_HPP

template<typename T>
class	Array
{
	public :

	Array();									//CANONICAL
	Array(unsigned int n);
	Array(Array const &src);					//CANONICAL
	~Array();									//CANONICAL

	Array&	operator=(Array const &rhs);		//CANONICAL

	unsigned int	size() const;

	class	IncorrectIndex : public std::exception
	{
		public :

		virtual const char *	what() const throw();
	}

	private :

	T				*elements;
	unsigned int	nb_elements;
};

#endif
