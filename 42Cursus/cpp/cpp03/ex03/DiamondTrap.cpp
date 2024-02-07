#include "DiamondTrap.hpp"

//CONSTRUCTOR

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	m_name = "Unknow";
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	ClapTrap::m_name = name + "_clap_name";
	m_name = name;
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 30;
	std::cout << "DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	ClapTrap::m_name = src.m_name + "_clap_name";
	m_name = src.m_name;
	m_hit_point = 100;
	m_energy_point = 50;
	m_attack_damage = 30;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

//DESTRUCTOR

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

//OPERATOR

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &rhs)
{
	(std::string)ClapTrap::m_name = rhs.m_name + "_clap_name";
	this->m_name = rhs.m_name;
	this->m_hit_point = rhs.m_hit_point;
	this->m_energy_point = rhs.m_energy_point;
	this->m_attack_damage = rhs.m_attack_damage;
	return *this;
}

//MEMBER FUNCTION

void	DiamondTrap::call_ScavAttack(std::string const name)
{
	ScavTrap::attack(name);
}

void	DiamondTrap::whoAmi(void)
{
	std::cout << "ClapTrap name : " << ClapTrap::m_name << std::endl;
	std::cout << "DiamondTrap name : " << m_name << std::endl;
}
