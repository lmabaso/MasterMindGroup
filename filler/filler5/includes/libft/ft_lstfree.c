#include "libft.h"

void	ft_lstfree(t_list *head)
{
	t_list *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
