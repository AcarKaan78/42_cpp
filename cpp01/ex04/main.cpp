#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define ARGS 0
#define INPUT 1
#define OUTPUT 2

int	PErr(int err)
{
	if (err == ARGS)
		std::cerr << "Error : wrong number of arguments, use ./replace file s1 s2" << std::endl;
	else if (err == INPUT)
		std::cerr << "Error : input file" << std::endl;
	else if (err == OUTPUT)
		std::cerr << "Error : output file" << std::endl;
	return (1);
}

void	StringChange(std::ofstream &fileOut, std::string s1, std::string s2, std::string input)
{
	size_t	position;
	size_t	Skip;

	position = input.find(s1);
	if (position == std::string::npos)
	{
		fileOut << input;
		return ;
	}
	else
	{
		fileOut << input.substr(0, position);
		fileOut << s2;
		Skip = position + s1.length();
		StringChange(fileOut, s1, s2, input.substr(Skip));
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	In;
	std::ofstream	Out;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	std::string		file;
	std::string		fileChange;

	if (argc != 4)
		return (PErr(ARGS));
	
	s1 = argv[2];
	s2 = argv[3];
	
	file = argv[1];
	In.open(file.c_str());
	if (In.good() == false)
		return (PErr(INPUT));
	
	fileChange = file + ".replace";
	Out.open(fileChange.c_str());
	if (Out.good() == false)
	{
		In.close();
		return (PErr(OUTPUT));
	}

	while (getline(In, buff))
		StringChange(Out, s1, s2, buff + '\n');
	
	In.close();
	Out.close();
	return (0);
}