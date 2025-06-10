#include "ClapTrap.hpp"

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

	return 0;
}
