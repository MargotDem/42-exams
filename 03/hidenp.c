#include "../exam.h"

void	hidenp(char *s1, char *s2)
{
	int 	i;
	int 	j;

	if (*s1 == '\0')
	{
		printf("1\n");
		return ;
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				j++;
				break ;
			}
			j++;
		}
		i++;
		if (s2[j - 1] != s1[i - 1])
		{
			printf("0\n");
			return ;
		}
	}
	printf("1\n");
}

int main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	else
		printf("\n");
}
