#include "Harl.hpp"

Harl::Harl()
{
	std::cout<<"Harl is created"<<std::endl;
}

Harl::~Harl()
{
	std::cout<<"Harl is deleted"<<std::endl;
}

void	Harl::complain(std::string level) const
{
	int			i = 0;
	std::string	message[4] = {"debug", "info", "warning", "error"};

	void	(Harl::*pmf[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (level != message[i] && i < 4)
		i++;
	if (i < 4)
		(this->*pmf[i])();
	else
		std::cout<<level<<" is not a level"<<std::endl;
}

void	Harl::debug(void) const
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"<<std::endl;
	std::cout<<"ketchup burger. I really do !"<<std::endl;
}

void	Harl::info(void) const
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put"<<std::endl;
	std::cout<<"enough bacon in my burger ! If you did, I wouldn't be asking for more !"<<std::endl;
}

void	Harl::warning(void) const
{
	std::cout<<"I think I deserve to have some extra bacon for free. I've been coming"<<std::endl;
	std::cout<<"for years whereas you started working here since last month."<<std::endl;
}

void	Harl::error(void) const
{
	std::cout<<"This is unacceptable ! I want to speak to the manager now."<<std::endl;
}
