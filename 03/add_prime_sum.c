#include "../exam.h"

int	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void addprime(int nbr)
{
	int i;
	int sum;

	i = 2;
	sum = 0;
	while (i <= nbr)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	printf("%d\n", sum);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		addprime(atoi(argv[1]));
	}
	else
	{
		write(1, "0\n", 2);
	}
}
