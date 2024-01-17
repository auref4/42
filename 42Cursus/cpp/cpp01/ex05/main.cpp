#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout<<std::endl;
	harl.complain("debug");
	std::cout<<std::endl;
	harl.complain("info");
	std::cout<<std::endl;
	harl.complain("warning");
	std::cout<<std::endl;
	harl.complain("error");
	std::cout<<std::endl;
	harl.complain("test");
	std::cout<<std::endl;
}
