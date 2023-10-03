#include <iostream>

int megaphone(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			megaphone(av[i]);
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}