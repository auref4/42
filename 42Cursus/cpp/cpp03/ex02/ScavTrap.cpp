#include "ScavTrap.hpp"

//CONSTRUCTOR

ScavTrap::ScavTrap() : ClapTrap()
{
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 20;
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 20;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

//DESTRUCTOR

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

//OPERATOR

ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs)
{
	(std::string)this->m_name = rhs.m_name;
	this->m_hit_point = rhs.m_hit_point;
	this->m_energy_point = rhs.m_energy_point;
	this->m_attack_damage = rhs.m_attack_damage;
	return *this;
}

//MEMBER FUNCTIONS

void	ScavTrap::guardGate(void)
{
	std::cout << this->m_name << " is now in Gate keeper mode." << std::endl;
}
