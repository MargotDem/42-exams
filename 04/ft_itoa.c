#include "../exam.h"

int		get_nb_size(int nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

int		ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	int		size;
	char	*str;
	char	*str_ptr;

	size = get_nb_size(nbr);
	if (nbr < 0)
		size++;
	str = (char *)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	str_ptr = str + size - 1;
	if (nbr < 0)
		str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	while (nbr)
	{
		*str_ptr = ft_abs(nbr % 10) + '0';
		str_ptr--;
		nbr = nbr / 10;
	}
	str[size] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	int		nb;
	char	*str;

	(void)argv;
	nb = -0;
	if (argc == 1)
	{
		str = ft_itoa(nb);
		printf("str is %s\n", str);
	}
	return (0);
}
