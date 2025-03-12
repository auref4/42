#include "FordJohnson.hpp"

template<typename C>
void	FordJohnson::sort_odd(C& container, const int& size_comparison)
{
	for (typename C::iterator it = container.begin(); it != container.end(); it += size_comparison)
	{
		if (std::distance(container.begin(), it) + size_comparison > static_cast<int>(container.size()))
			break;
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

template<typename C>
typename C::iterator	FordJohnson::binary_search(C& container, const int& nb_link, const int& to_insert, const int& size_comparison)
{
	typename C::iterator	link = std::find(container.begin(), container.end(), nb_link);
	typename C::iterator	i_binary = link - 1 - (link - 1 - container.begin()) / 2;
	int				half_distance = (link - i_binary) / 2 / size_comparison;

	if (half_distance < 1 || size_comparison == 2)
		half_distance = 1;
	while (1)
	{
		if (i_binary >= link)
			break;
		if (i_binary != container.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)) && to_insert > *(i_binary - 1))
			break;
		if (i_binary == container.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)))
			break;
		if (to_insert > *(i_binary + (size_comparison / 2 - 1)))
			i_binary += (half_distance * (size_comparison / 2));
		else
			i_binary -= (half_distance * (size_comparison / 2));
		if (half_distance > 1)
			half_distance /= 2;	
	}
	return i_binary;
}

template <typename C>
void	FordJohnson::insert_sorted(C& container, C& unsorted, const int& size_comparison)
{
	typename C::iterator	index_to_insert;
	int				nb_link;
	int				to_insert;

	for (typename C::iterator  it = unsorted.begin(); it != unsorted.end();)
	{
		nb_link = *(it + (size_comparison / 2));
		to_insert = *(it + (size_comparison / 2 - 1));
		index_to_insert = this->binary_search(container, nb_link, to_insert, size_comparison);	
		it += (size_comparison / 2) - 1;
		for (int i = (size_comparison / 2) - 1; i > 0; i--)
		{
			index_to_insert = container.insert(index_to_insert, *it);
			it = unsorted.erase(it);
			it--;	
		}
		container.insert(index_to_insert, *it);
		it = unsorted.erase(it);
		it = unsorted.erase(it);
		if (std::distance(unsorted.begin(), it) + (size_comparison / 2) + 1 > static_cast<int>(unsorted.size()))
			break;
	}
}

template <typename C>
void	FordJohnson::sort(C& container)
{
	C	unsorted;	
	int	size_comparison = 2;

	while (size_comparison < static_cast<int>(container.size()))
	{
		this->sort_odd(container, size_comparison);
		size_comparison *= 2;
	}
	while (size_comparison >= 2)
	{
		this->push_unsorted(container, unsorted, size_comparison);
		this->insert_sorted(container, unsorted, size_comparison);
		unsorted.clear();
		size_comparison /= 2;
	}
}
