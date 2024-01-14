#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <exception>

int	replace_argv(std::ifstream &ifs, std::ofstream &ofs, char *s1, char *s2)
{
	int			i = 0;
	int			j;
	std::string	str_tmp;
	std::string	str2 = (const char *)s2;

	while (getline(ifs, str_tmp))
	{
		std::istringstream	line(str_tmp);
		std::string			word;
		if (i > 0)
			ofs<<std::endl;
		j = 0;
		while (line>>word)
		{
			if (j > 0)
				ofs<<" ";
			if (word == (const char *)s1)
			{
				if (str2.size() > 0)
					word = str2;
			}
				ofs<<word;
			j++;
		}
		i++;
	}
	if (i > 0)
		ofs<<std::endl;
	return (1);
}

int	open_files(char **argv)
{
	std::string		str_tmp;
	std::string		replace = ".replace";
	std::string		join = (const char *)argv[1] + replace;
	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs(join.c_str());

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
	replace_argv(ifs, ofs, argv[2], argv[3]);
	ifs.close();
	ofs.close();
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		try
		{
			open_files(argv);
		}
		catch (std::exception &error)
		{
			std::cout<<"ERROR "<<error.what()<<std::endl;
			return (0);
		}
	}
	else
		std::cerr<<"Incorrect number of arguments"<<std::endl;
	return (0);
}
