#include "../exam.h"

int	brackets(char *str)
{
	// ( ) { } [ ]
	int i;
	char close;
	int	ar[3];
	int	bracket;

	i = 0;
	if (str[0] == '\n')
		return (1);
	bracket = NULL;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			if (str[i] == '(')
			{
				close = ')';
			}
			else if (str[i] == '{')
				close = '}';
			else
				close = ']';
		}
		if (str[i] == ')' && close != ')')
		{
			printf("du är här 1. close is %c\n", close);
			return (0);
		}
		else if (str[i] == '}' && close != '}')
		{
			printf("du är här 2\n");
			return (0);
		}
		else if (str[i] == ']' && close != ']')
		{
			printf("du är här 3\n");
			return (0);
		}
		i++;		
	}
	return (1);
}
/*
now wait a second.
am i actually fucking stupid??? you need to remember the one before, so some sort of pile SMH why am i like this

*/

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
