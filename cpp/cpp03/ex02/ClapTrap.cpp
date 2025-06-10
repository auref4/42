#include "ClapTrap.hpp"

//CONSTRUCTOR

ClapTrap::ClapTrap() : m_name("Unknow"), m_hit_point(10), m_energy_point(10), m_attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : m_name(name), m_hit_point(10), m_energy_point(10), m_attack_damage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : m_name(src.m_name), m_hit_point(src.m_hit_point), m_energy_point(src.m_energy_point),
m_attack_damage(src.m_attack_damage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

//DESTRUCTOR

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

//OPERATOR

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
{
	(std::string)this->m_name = rhs.m_name;
	this->m_hit_point = rhs.m_hit_point;
	this->m_energy_point = rhs.m_energy_point;
	this->m_attack_damage = rhs.m_attack_damage;
	return *this;
}

//MEMBER FUNCTIONS

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "Hit_point " << this->m_name << " before attack : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " before attack : " << this->m_energy_point << std::endl;

	if (this->m_energy_point == 0 || this->m_hit_point == 0)
	{
		std::cout <<"ClapTrap " << this->m_name <<" cant attack " << target << std::endl;
		return ;
	}

	std::cout <<"ClapTrap " << this->m_name <<" attacks " << target;
	std::cout <<" causing " << this->m_attack_damage << " points of damage!" << std::endl;

	this->m_energy_point -= 1;

	std::cout << "Hit_point " << this->m_name << " after attack : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " after attack : " << this->m_energy_point << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	std::cout << "Hit_point " << this->m_name << " before take damage : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " before take damage : " << this->m_energy_point << std::endl;
	std::cout <<"ClapTrap " << this->m_name <<" taken " << amout << " points of damage!" << std::endl;

	this->m_hit_point -= amout;
	if (this->m_hit_point < 0)
		this->m_hit_point = 0;

	std::cout << "Hit_point " << this->m_name << " after take damage : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " after take damage : " << this->m_energy_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	std::cout << "Hit_point " << this->m_name << " before be repaired : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " before be repaired : " << this->m_energy_point << std::endl;

	if (this->m_energy_point == 0 || this->m_hit_point == 0)
	{
		std::cout <<"ClapTrap " << this->m_name <<" cant be repaired " << std::endl;
		return ;
	}

	std::cout <<"ClapTrap " << this->m_name <<" was repaired by " << amout << " hit points!" << std::endl;

	this->m_energy_point -= 1;
	this->m_hit_point += amout;
	if (this->m_hit_point > 10)
		this->m_hit_point = 10;

	std::cout << "Hit_point " << this->m_name << " after be repaired : " << this->m_hit_point << std::endl;
	std::cout << "Energy_point " << this->m_name << " after be repaired : " << this->m_energy_point << std::endl;
}
