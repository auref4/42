#ifndef FORDJOHNSON_HPP
#define FORDJOHNSON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <iterator>
#include <deque>
#include <vector>
#include <cmath>
#include <ctime>

template <typename Iterator>
struct	LocalVariables
{
	int		nb_link;
	int		to_insert;
	int		size_to_insert;
	int		i_while;
	Iterator	it;
	Iterator	index_to_insert;
};

class	FordJohnson
{
	public :

	FordJohnson();								//CANONICAL
	FordJohnson(FordJohnson const& src);					//CANONICAL
	~FordJohnson();								//CANONICAL

	FordJohnson&	operator=(FordJohnson const& rhs);			//CANONICAL

	template <typename C>
	void	sort(C& container);

	private :

	template <typename C>
	void	sort_odd(C& container, const int& size_comparison);

	template <typename C>		
	void	push_unsorted(C& container, C& unsorted, const int& size_comparison);

	template <typename C, typename Iterator>
	void	init_variables(struct LocalVariables<Iterator>& lc, C& unsorted, const int& size_comparison);

	int	index_jacobsthal(const int& n);

	template <typename C>
	void	insert_sorted(C& container, C& unsorted, const int& size_comparaison);

	template <typename C>
	typename C::iterator	binary_search(C& container, const int& nb_link, const int& to_insert, const int& size_comparaison);
};

#include "FordJohnson.tpp"

#endif
