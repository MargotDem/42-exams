#include "../exam.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

int main(void)
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

	printf("list size is %d\n", ft_list_size(list));
}