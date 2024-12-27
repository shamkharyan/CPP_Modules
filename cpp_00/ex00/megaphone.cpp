#include <iostream>
#include <cctype>

void	makeUpperCase(char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		arr[i] = std::toupper(arr[i]);
		++i;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			makeUpperCase(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}