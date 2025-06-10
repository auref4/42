#include "Template.hpp"

int	main(void)
{
	int			nb1 = 4;
	int			nb2 = 2;
	std::string	str1 = "bonjour";
	std::string	str2 = "aurevoir";

	std::cout << "TEST 1 :" << std::endl;
	std::cout << "before swap :" << std::endl;
	std::cout << "nb1 = " << nb1 << std::endl;
	std::cout << "nb2 = " << nb2 << std::endl;
	swap(nb1, nb2);
	std::cout << "after swap :" << std::endl;
	std::cout << "nb1 = " << nb1 << std::endl;
	std::cout << "nb2 = " << nb2 << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 2 :" << std::endl;
	std::cout << "before swap :" << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "after swap :" << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "str2 = " << str2 << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 3 :" << std::endl;
	std::cout << "nb1 = " << nb1 << std::endl;
	std::cout << "nb2 = " << nb2 << std::endl;
	std::cout << "min = " << min(nb1, nb2) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 4 :" << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "str2 = " << str2 << std::endl;
	std::cout << "min = " << min(str1, str2) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 5 :" << std::endl;
	std::cout << "nb1 = " << nb1 << std::endl;
	std::cout << "nb2 = " << nb2 << std::endl;
	std::cout << "max = " << max(nb1, nb2) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 4 :" << std::endl;
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "str2 = " << str2 << std::endl;
	std::cout << "max = " << max(str1, str2) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST 42 :" << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
