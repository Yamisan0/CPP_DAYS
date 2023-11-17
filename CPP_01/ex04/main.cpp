#include "sed.hpp"

int main(int ac, char **av)
{
	std::string buff;
	int pos;
	if (ac != 4)
		std::cerr << "3 arguments needed!" << std::endl;
	else
	{
		std::string to_replace(av[2]);
		std::string to_write(av[3]);
		std::string file_to_create(av[1]);
		std::ifstream inputfile(av[1]);
		file_to_create.append(".replace");
		std::ofstream outputfile(file_to_create.c_str());
		if (!inputfile.is_open())
		{
			std::cerr << "Failed to open the file " << std::endl;
			return 0;
		}
		while (std::getline(inputfile, buff))
		{
			while ((pos = buff.find(av[2]))!= -1)
			{
				buff.erase(pos, to_replace.length());
				buff.insert(pos, to_write);
			}
			buff.append("\n");
			outputfile.write(buff.c_str(), buff.length());
		}
	}
} 