#include "../exam.h"

int	str_len(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		i++;
	}
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	expand(char *str)
{
	int	i;
	int	len;

	len = str_len(str);
	i = len - 1;
	while (str[i] == ' ' || str[i] == '\t')
	{
		len--;
		i--;
	}
	i = 0;
	while (i < len)
	{
		i += print_word(&str[i]);
		if (i != len)
			write(1, "   ", 3);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		expand(argv[1]);
	}
	else
	{
		write(1, "\n", 1);
	}
}
