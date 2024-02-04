#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::manage(std::string level)
{
	int	i;
	std::string	message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
	{
		if (level == message[i])
			break;
	}
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "Incorrect message" << std::endl;
	}
}

void	Harl::debug(void) const
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"<<std::endl;
	std::cout<<"ketchup burger. I really do !"<<std::endl;
	std::cout << std::endl;
}

void	Harl::info(void) const
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put"<<std::endl;
	std::cout<<"enough bacon in my burger ! If you did, I wouldn't be asking for more !"<<std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void) const
{
	std::cout<<"I think I deserve to have some extra bacon for free. I've been coming"<<std::endl;
	std::cout<<"for years whereas you started working here since last month."<<std::endl;
	std::cout << std::endl;
}

void	Harl::error(void) const
{
	std::cout<<"This is unacceptable ! I want to speak to the manager now."<<std::endl;
}
