#include "filler.h"

t_list	*ft_get_available_move(t_spot **board, t_obj input)
{
	int 	i;
	int 	j;
	t_co	*tmp;
	t_list	*head;

	head = NULL;
	i = 0;
	tmp = NULL;
	if (!(tmp = (t_co *)malloc(sizeof(t_co))))
		return (NULL);
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			if (board[i][j].state == input.mypiece)
			{
				tmp->y = i;
				tmp->x = j;
				ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
			}
			j++;
		}
		i++;
	}
	return (head);
}