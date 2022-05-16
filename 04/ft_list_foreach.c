#include "../exam.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

int	main(void)
{
	//ft_list_foreach();
	return (0);
}

/*

wait how the hell is this a level 4 exercise?? are these exercices fake or something?

*/