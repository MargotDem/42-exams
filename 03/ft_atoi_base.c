#include "../exam.h"

int	is_acceptable(char c, int base)
{
	char	*str = "abcdef";
	char	*str2 = "ABCDEF";
	int	i;

	if (c >= '0' && c <= '9')
		return (1);
	i = 0;
	while (i < base - 10)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < base - 10)
	{
		if (c == str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	while (str[i])
	{
		if (!is_acceptable(str[i], str_base))
			return (nb);
		nb = nb * str_base + get_digit(str[i]);
		i++;
	}
	return (nb * sign);
}

int	main(int argc, char **argv)
{
	int	nb;

	if (argc == 2)
	{
		nb = ft_atoi_base(argv[1], 10);
		printf("nb is %d\n", nb);
	}
	return (0);
}
