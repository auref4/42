#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void	replace_occurence(std::ifstream &ifs, std::ofstream &ofs, char *s1, char *s2)
{
	int			i = 0;
	size_t		start_pos;
	size_t		pos;
	std::string	str_tmp;
	std::string	str1 = (const char *)s1;
	std::string	str2 = (const char *)s2;

	while (getline(ifs, str_tmp))
	{
		if (i > 0)
			ofs << "\n";
		start_pos = 0;
		while (start_pos < str_tmp.length())
		{
			pos = str_tmp.find(s1, start_pos);
			if (pos != std::string::npos)
				str_tmp.replace(pos, str1.length(), str2);
			else
				break ;
			start_pos = pos + str2.length();
		}
		ofs << str_tmp;
		i++;
	}
	ofs << "\n";
}

bool	open_files(std::ifstream &ifs, std::ofstream &ofs)
{
	if (ifs.is_open() == false)
	{
		std::cerr << "Infile error" << std::endl;
		return false;
	}
	if (ofs.is_open() == false)
	{
		std::cerr << "Outfile error" << std::endl;
		ifs.close();
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == 0)
		{
			std::cerr << "Impossible to replace void occurence" << std::endl;
			return 0;
		}

		std::string		replace = ".replace";
		std::string		join = (const char *)argv[1] + replace;
		std::ifstream	ifs(argv[1]);
		std::ofstream	ofs(join.c_str());

		if (open_files(ifs, ofs) == true)
		{
			replace_occurence(ifs, ofs, argv[2], argv[3]);
			ifs.close();
			ofs.close();
		}
	}
	else
		std::cerr << "Incorrect number of arguments" << std::endl;
	return 0;
}
