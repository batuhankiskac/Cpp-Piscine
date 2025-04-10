#include <iostream>

int main(int argc, char const *argv[])
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			str = *argv;
			for (size_t i = 0; i < str.length(); i++)
				str[i] = std::toupper(str[i]);
			std::cout << str;
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
