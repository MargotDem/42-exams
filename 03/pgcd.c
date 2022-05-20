#include "../exam.h"

void	pgcd(int a, int b)
{
	int pgcd;
	int i;

	if (b < a){
		i = a;
		a = b;
		b = i;
	}
	i = 1;
	while (i < b)
	{
		if (a % i == 0 && b % i == 0)
			pgcd = i;
		i++;
	}
	printf("%d", pgcd);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		pgcd(atoi(argv[1]), atoi(argv[2]));
	}
	printf("\n");
}
