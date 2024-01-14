#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

int	manage_argv(char **argv)
{
	char	*replace = ".replace";
	char	*join = argv[1] + replace;
	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs(join);

	if (ifs.is_open() == false)
	{
		std::cerr<<"file '"<<argv[1]<<"' doesn't exist"<<std::endl;
		return (0);
	}
	if (ofs.is_open() == false)
	{
		std::cerr<<"file '"<<join<<"' failed to be create"<<std::endl;
		return (0);
	}
	ifs>>ofs;
	ifs.close();
	ofs.close();
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		manage_argv(argv);
	else
		std::cerr<<"Incorrect number of arguments"<<std::endl;
	return (0);
}
