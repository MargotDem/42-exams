#include "../exam.h"

int     *ft_range(int start, int end)
{
	int	*array;
	int	size;
	int	tmp;
	int	reverse;

	reverse = 0;
	if (start > end)
	{
		tmp = start;
		start = end;
		end = tmp;
		reverse = 1;
	}
	size = end - start + 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	tmp = 0;
	while (tmp < size)
	{
		if (reverse)
			array[size - tmp - 1] = start + tmp;
		else
			array[tmp] = start + tmp;
		tmp++;
	}
	return (array);
}

int ft_abs(int nb)
{
	if (nb < 0)
		nb = - nb;
	return (nb);
}

int	main(void)
{
	int	*array;
	int start = 1;
	int end = 1;
	int i;

	array = ft_range(start, end);
	i = 0;
	while (i < ft_abs(end - start) + 1)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}