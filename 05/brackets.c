#include "../exam.h"

int matches(char opening, char closing)
{
	if ((opening == '(' && closing == ')') || \
		(opening == '{' && closing == '}') || \
		(opening == '[' && closing == ']'))
		return (1);
	return (0);
}

int	brackets(char *str)
{
	char *pile;
	char *pile_ptr;
	char *tmp;
	int pile_size;
	int i;

	pile_size = 3;
	pile = (char *)malloc(sizeof(char *) * pile_size);
	if (!pile)
		return (0);
	i = 0;
	pile_ptr = pile;
	while (str[i])
	{
		if (pile_ptr - pile == pile_size)
		{
			tmp = (char *)malloc(sizeof(char *) * pile_size * 2);
			if (!tmp)
				return (0);
			int j = 0;
			while (j < pile_size)
			{
				tmp[j] = pile[j];
				j++;
			}
			free(pile);
			pile = tmp;
			pile_ptr = pile + pile_size;
			pile_size *= 2;
		}
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			*pile_ptr = str[i];
			*(pile_ptr + 1) = '\0';
			pile_ptr++;
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (!matches(*(pile_ptr - 1), str[i]))
			{
				free(pile);
				return (0);
			}
			else
			{
				pile_ptr--;
				*pile_ptr = 0;
			}
		}
		i++;
	}
	if (pile_ptr - pile != 0)
	{
		free(pile);
		return (0);
	}
	free(pile);
	return (1);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i <= argc - 1)
		{
			if (brackets(argv[i]))
				printf("OK\n");
			else
				printf("Error\n");
			i++;
		}
	}
	else
		printf("\n");
}
