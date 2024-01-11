#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout<<"Adress of str = "<<&str<<std::endl;
	std::cout<<"Adress of stringPTR = "<<&stringPTR<<std::endl;
	std::cout<<"Adress of stringREF = "<<&stringREF<<std::endl;

	std::cout<<"Value of str = "<<str<<std::endl;
	std::cout<<"Value of stringPTR = "<<stringPTR<<std::endl;
	std::cout<<"Value of stringREF = "<<stringREF<<std::endl;

	return (0);
}
