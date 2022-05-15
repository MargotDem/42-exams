#include "../exam.h"

void	display_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int total;
	int	tmp;

	i = 0;
	total = 0;
	display_tab(tab, size);
	printf("\n");
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
			total++;
		}
		i++;
	}
	display_tab(tab, size);
	printf("total is %d\n", total);
}

int	main(void)
{
	//int	tab[5] = {10, 0, 4, 6, 3};
	//int	tab3[5] = {10, -5, 8, 2, -184743};
	int	tab4[5] = {5, 4, 3, 2, 1};
	//int	tab2[0] = {};


	sort_int_tab(tab4, 5);
	return (0);
}
