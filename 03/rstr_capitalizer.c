#include "../exam.h"

void	print_up(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	write(1, &c, 1);
}

void	print_low(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	write(1, &c, 1);
}

void	capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			print_up(str[i]);
		else
			print_low(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		capitalize(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
}
