#include "../exam.h"

int	get_list_size(t_list *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	switch_els(t_list **begin, t_list *prev, t_list *cur, t_list *next)
{
	t_list	*tmp;

	tmp = next->next;
	next->next = cur;
	cur->next = tmp;
	if (!prev)
		*begin = next;
	else
		prev->next = next;
}

//vitun brain fog. alright
void	display_list(t_list *lst)
{
	// go through list without swithcing anything
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	next = lst->next;
	while (lst)
	{
		if (prev)
			printf("prev is %d. ", (int)prev->data);
		else
			printf("prev is null. ");
		printf("el is: %d\n", (int)lst->data);
		next = lst->next;
		prev = lst;
		lst = next;
	}
}

int		cmp(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int size = get_list_size(lst);
	int i;
	t_list	*prev;
	t_list	*next;
	t_list	*tmp;
	t_list	*begin_list;

	i = 0;
	begin_list = lst;
	while (i < size)
	{
		lst = begin_list;
		prev = NULL;
		next = lst->next;
		while (lst->next)
		{
			if ((*cmp)((int)lst->data, (int)lst->next->data) == 0)
			{
				tmp = next->next;
				switch_els(&begin_list, prev, lst, next);
				prev = next;
				next = tmp;
			}
			else
			{
				next = next->next;
				prev = lst;
				lst = lst->next;
			}
		}
		i++;
	}
	return (begin_list);
}

t_list	*sort_list2(t_list* lst, int (*cmp)(int, int))
{
	t_list	*prev;
	t_list	*next;
	t_list	*begin_list;

	begin_list = lst;
	prev = NULL;
	next = lst->next;
	while (lst->next)
	{
		if ((*cmp)((int)lst->data, (int)lst->next->data) == 0)
		{
			switch_els(&begin_list, prev, lst, next);
			lst = begin_list;
			prev = NULL;
			next = lst->next;
		}
		else
		{
			next = next->next;
			prev = lst;
			lst = lst->next;
		}
	}
	return (begin_list);
}

int	main(void)
{
	t_list	*list;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst4;

	lst1 = (t_list *)malloc(sizeof(t_list *));
	lst1->next = NULL;
	lst1->data = (void *)1345;

	lst2 = (t_list *)malloc(sizeof(t_list *));
	lst2->data = (void *)56;
	lst2->next = NULL;
	lst1->next = lst2;

	lst3 = (t_list *)malloc(sizeof(t_list *));
	lst3->data = (void *)-23;
	lst3->next = NULL;
	lst2->next = lst3;

	lst4 = (t_list *)malloc(sizeof(t_list *));
	lst4->data = (void *)103;
	lst4->next = NULL;
	lst3->next = lst4;

	list = lst1;

	printf("\n\n");

	printf("list before: \n");
	display_list(list);


	printf("\n\n");
	list = sort_list(list, &cmp);

	printf("\n\n");
	printf("list after: \n");
	display_list(list);

	return (0);
}
