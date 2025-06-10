#include "FragTrap.hpp"

//CONSTRUCTOR

FragTrap::FragTrap() : ClapTrap()
{
	m_hit_point = 100;
	m_energy_point = 100;
	m_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	m_hit_point = 100;
	m_energy_point = 100;
	m_attack_damage = 30;
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	m_hit_point = 100;
	m_energy_point = 100;
	m_attack_damage = 30;
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

//DESTRUCTOR

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

//OPERATOR

FragTrap&	FragTrap::operator=(FragTrap const &rhs)
{
	(std::string)this->m_name = rhs.m_name;
	this->m_hit_point = rhs.m_hit_point;
	this->m_energy_point = rhs.m_energy_point;
	this->m_attack_damage = rhs.m_attack_damage;
	return *this;
}

//MEMBER FUNCTIONS

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->m_name << " *make a hight fives*" << std::endl;
}
