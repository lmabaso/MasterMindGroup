#include "libft.h"

int 	ft_lstlen(t_list *lst)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}