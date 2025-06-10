#ifndef PEMERGEME_HPP
#define PEMERGEME_HPP

#include "FordJohnson.hpp"
#include <unistd.h>
#include <cstdlib>

void	first_screen(std::deque<int>& deque);
void	second_screen(std::deque<int>& deque);
void	third_screen(double d1, double d2, FordJohnson& fj);
void	print_container(std::deque<int>& deque);
bool	check_sort(std::deque<int>& deque, int nb);

#endif
