#include "../exam.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
		write(1, "a\n", 2);
	else
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (str[i] == 'a')
			{
				write(1, "a", 1);
				break ;
			}
			i++;
		}
		write(1, "\n", 1);
	}
}
