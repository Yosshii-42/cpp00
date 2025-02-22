#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		
	for (int i(1); i < argc; i++) {
		std::string	uppered;
		for (int j(0); argv[i][j]; j++) {
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				uppered += toupper(argv[i][j]);
			else
				uppered += argv[i][j];
		}
		std::cout << uppered;
	}
	std::cout << std::endl;
	return (0);
}
