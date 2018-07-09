#include "filler.h"

t_list		*ft_get_neighbours(int y, int x, t_obj input)
{
	t_list *head;
	t_co *tmp;

	head = NULL;
	tmp = NULL;
	if (!(tmp = (t_co *)malloc(sizeof(t_co))))
		return (NULL);
	if (x < input.bx - 1)
	{
		tmp->x = x + 1;
		tmp->y = y;
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	if (x > 0)
	{
		tmp->x = x - 1;
		tmp->y = y;
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	if (y < input.by - 1)
	{
		tmp->y = y + 1;
		tmp->x = x;
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	}
	if (y > 0)
	{
		tmp->y = y - 1;
		tmp->x = x;
		ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
	} 
	return (head);
}
