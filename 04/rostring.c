#include "../exam.h"

void	display_word(char *str, size_t *i)
{
	while (str[*i] && str[*i] != ' ')
	{
		write(1, &str[*i], 1);
		(*i)++;
	}
	write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	size_t	first_start;
	size_t	first_end;
	size_t	i;
	size_t	is_word;
	size_t	word_count;
	char	*str;

	if (argc >= 2)
	{
		str = argv[1];
		first_start = 0;
		first_end = 0;
		is_word = 0;
		word_count = 1;
		i = 0;
		while (str[i] && str[i] == ' ')
			i++;
		first_start = i;
		while (str[i] && str[i] != ' ')
			i++;
		first_end = i;
		while (str[i])
		{
			if (str[i] == ' ' && is_word)
			{
				write(1, " ", 1);
				is_word = 0;
			}
			if (str[i] != ' ')
			{
				if (is_word == 0)
				{
					word_count++;
					is_word = 1;
				}
				write(1, &str[i], 1);
			}
			i++;
		}
		if (word_count > 1)
			write(1, " ", 1);
		write(1, &str[first_start], first_end - first_start);
	}
	write(1, "\n", 1);
}
