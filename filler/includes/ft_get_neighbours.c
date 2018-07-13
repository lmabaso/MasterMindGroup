#include "filler.h"

void		ft_neighbours(int y, int x, t_obj input, t_co **temp, t_list **rhead)
{
	t_co	*tmp;
	t_list	*head;

	tmp = *temp;
	head = *rhead;
	if (y < input.by - 1)
	{
		ft_put_to_co(tmp, x, y + 1);
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	if (y > 0)
	{
		ft_put_to_co(tmp, x, y - 1);
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	*temp = tmp;
	*rhead = head;
}

t_list		*ft_get_neighbours(int y, int x, t_obj input)
{
	t_list	*head;
	t_co	*tmp;

	head = NULL;
	tmp = NULL;
	if (!(tmp = (t_co *)malloc(sizeof(t_co))))
		return (NULL);
	if (x < input.bx - 1)
	{
		ft_put_to_co(tmp, x + 1, y);
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	if (x > 0)
	{
		ft_put_to_co(tmp, x - 1, y);
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	ft_neighbours(y, x, input, &tmp, &head);
	return (head);
}
