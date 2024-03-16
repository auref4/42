#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	robot("Clank");

	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.takeDamage(7);
	std::cout << std::endl;
	robot.beRepaired(3);
	std::cout << std::endl;
	robot.beRepaired(10);
	std::cout << std::endl;
	robot.takeDamage(9);
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.attack("Ratchet");
	std::cout << std::endl;
	robot.beRepaired(10);
	std::cout << std::endl;

	ClapTrap	robot_2("R2-D2");

	std::cout << std::endl;
	robot_2.takeDamage(12);
	std::cout << std::endl;
	robot_2.attack("C-3PO");
	std::cout << std::endl;
	robot_2.beRepaired(10);
	std::cout << std::endl;

	ScavTrap	robot_3("wall-e");

	std::cout << std::endl;
	robot_3.guardGate();
	std::cout << std::endl;
	robot_3.attack("Robocop");
	std::cout << std::endl;

	FragTrap	robot_4;

	std::cout << std::endl;
	robot_4.highFivesGuys();
	std::cout << std::endl;
	robot_4.attack("Robocop");
	std::cout << std::endl;

	DiamondTrap	robot_5("MultiRobot");

	std::cout << std::endl;
	robot_5.whoAmi();
	std::cout << std::endl;
	robot_5.call_ScavAttack("Robocop");
	std::cout << std::endl;
	robot_5.highFivesGuys();
	std::cout << std::endl;
	robot_5.guardGate();
	std::cout << std::endl;

	return 0;
}
