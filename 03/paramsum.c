#include "../exam.h"

void	print_nb(int nb)
{
	char	c;

	if (nb > 9)
	{
		print_nb(nb / 10);
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	print_nb(argc - 1);
	write(1, "\n", 1);
}
