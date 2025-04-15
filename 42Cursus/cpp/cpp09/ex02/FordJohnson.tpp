#include "FordJohnson.hpp"

template<typename C>
void	FordJohnson::sort_odd(C& container, const int& size_comparison)
{
	for (typename C::iterator it = container.begin(); it != container.end(); it += size_comparison)
	{
		if (std::distance(container.begin(), it) + size_comparison > static_cast<int>(container.size()))
			break;
		this->_comparisons++;
		std::cout << "_comparisons increment = " << this->_comparisons << std::endl;
		if (*(it + (size_comparison / 2) - 1) > *(it + size_comparison - 1))
			std::swap_ranges(it, it + (size_comparison / 2), it + (size_comparison / 2));
	}
}

template<typename C>
void	FordJohnson::push_unsorted(C& container, C& unsorted, const int& size_comparison)
{
	for (typename C::iterator	it = container.begin() + size_comparison; it != container.end(); it += size_comparison / 2)
	{
		if (std::distance(container.begin(), it) + (size_comparison / 2) > static_cast<int>(container.size()))
			break;
		for (int i = 0; i < (size_comparison / 2); i++)
		{
			unsorted.push_back(*it);
			it = container.erase(it);
		}
		if (it != container.end())
			unsorted.push_back(*it);
	}
}

template<typename C, typename Iterator>
void	FordJohnson::push_sorted(struct LocalVariables<Iterator>& lv, C& unsorted, C& container)
{
	for (int i = 0; i < lv.size_to_insert; i++)
	{
		if (lv.it != unsorted.end())
		{
			lv.index_to_insert = container.insert(lv.index_to_insert, *lv.it);
			lv.it = unsorted.erase(lv.it);
		}
		if (i < lv.size_to_insert - 1  && lv.it != unsorted.begin())
			lv.it--;
	}
	if (unsorted.empty() == false && lv.it != unsorted.end())
		lv.it = unsorted.erase(lv.it);

}

template<typename C>
typename C::iterator	FordJohnson::binary_search(C& container, const int& nb_link, const int& to_insert, const int& size_comparison)
{
	typename C::iterator	link = std::find(container.begin(), container.end(), nb_link);
	typename C::iterator	to_compare;
	int			size_groups = size_comparison / 2;
	int			first_half = 0;
	int			mid;
	int			second_half = std::distance(container.begin(), link) / size_groups;
//	bool			b = false;
	std::cout << "to_insert = " << to_insert << std::endl;
	std::cout << "nb groups = " << second_half << std::endl;
	while (first_half < second_half)
	{
		mid = first_half + (second_half - first_half) / 2;
//		if (second_half == 2 && b == false)
//		{
//			b = true;
//			mid -= 1;
//		}
		to_compare = container.begin() + (size_groups * mid);
		if (std::distance(to_compare, link) >= size_groups - 1)
			to_compare += size_groups - 1;
		else
			to_compare += std::distance(to_compare, link) - 1;
		std::cout << "mid = " << mid << std::endl;
		this->_comparisons++;
		std::cout << "_comparisons increment = " << this->_comparisons << std::endl;
		if (to_insert < *to_compare)
			second_half = mid;
		else
			first_half = mid + 1;
	}
	typename C::iterator	result = container.begin() + (first_half * size_groups);
	std::cout << "insert at " << *result << std::endl;
	std::cout << std::endl;
	return container.begin() + (first_half * size_groups);
}

template <typename C, typename Iterator>
void	FordJohnson::init_variables(struct LocalVariables<Iterator>& lv, C& unsorted, const int& size_comparison)
{
	int	i_jacobsthal = this->index_jacobsthal(lv.n);
	int	size_elements = (size_comparison / 2 + 1);
	int	modulo = 0;

	lv.it = unsorted.begin();
	if ((unsorted.size() % size_elements) != 0)
		modulo = 1;
	if (((static_cast<int>(unsorted.size()) / size_elements) + modulo) < (i_jacobsthal - lv.already_insert))
	{
		lv.n = 2;
		i_jacobsthal = 1;
		lv.already_insert = 0;
	}
	lv.it += (size_elements * (i_jacobsthal - 1 - lv.already_insert));
	if (lv.it == unsorted.begin())
		lv.change_n_jacobsthal = true;
	if (std::distance(lv.it, unsorted.end()) < size_elements)
	{
		lv.nb_link = -1;
		lv.to_insert = *(unsorted.end() - 1);
		lv.size_to_insert = static_cast<int>(std::distance(lv.it, unsorted.end()));
		lv.it = unsorted.end() - 1;
	}
	else
	{
		lv.nb_link = *(lv.it + size_elements - 1);
		lv.to_insert = *(lv.it + size_elements - 2);
		lv.size_to_insert = size_elements - 1;
		lv.it += size_elements - 2;
	}
}

template <typename C>
void	FordJohnson::manage_unsorted(C& container, C& unsorted, const int& size_comparison)
{
	LocalVariables<typename C::iterator>	lv;

	lv.n = 2;
	lv.already_insert = 0;
	lv.change_n_jacobsthal = false;
	while (unsorted.empty() == false)
	{
		this->init_variables(lv, unsorted, size_comparison);	
		lv.index_to_insert = this->binary_search(container, lv.nb_link, lv.to_insert, size_comparison);
		this->push_sorted(lv, unsorted, container);
		lv.already_insert++;
		if (lv.change_n_jacobsthal == true)
		{
			lv.n++;
			lv.change_n_jacobsthal = false;
		}
	}
}

template <typename C>
void	FordJohnson::sort(C& container)
{
	C	unsorted;	
	int	size_comparison = 2;

	this->_comparisons = 0;
	while (size_comparison <= static_cast<int>(container.size()))
	{
		std::cout << "size_comparaison / 2 = " << size_comparison / 2 << std::endl;
		std::cout << "sorted : ";
		for (int i = 0; i < static_cast<int>(container.size()); i++)
			std::cout << container[i] << " ";
		std::cout << std::endl;
		std::cout << "unsorted : ";
		for (int i = 0; i < static_cast<int>(unsorted.size()); i++)
			std::cout << unsorted[i] << " ";
		std::cout << std::endl << std::endl;

		this->sort_odd(container, size_comparison);
		size_comparison *= 2;
	}
	while (size_comparison >= 2)
	{
		std::cout << "size_comparaison / 2 = " << size_comparison / 2 << std::endl;
		std::cout << "sorted : ";
		for (int i = 0; i < static_cast<int>(container.size()); i++)
			std::cout << container[i] << " ";
		std::cout << std::endl;

		this->push_unsorted(container, unsorted, size_comparison);

		std::cout << "unsorted : ";
		for (int i = 0; i < static_cast<int>(unsorted.size()); i++)
			std::cout << unsorted[i] << " ";
		std::cout << std::endl << std::endl;

		this->manage_unsorted(container, unsorted, size_comparison);
		unsorted.clear();
		size_comparison /= 2;
	}
	std::cout << "_comparisons = " << _comparisons << std::endl << std::endl;
}
