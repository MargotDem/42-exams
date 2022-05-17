#include "../exam.h"

void	fprime(int nb)
{
	int	i;

	i = 2;
	while (nb >= i)
	{
		//if is cleanly divisible by i
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb != i)
				printf(" * ");
			nb = nb / i;
			i--;
		}
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	else
	{
		write(1, "\n", 1);
	}
}