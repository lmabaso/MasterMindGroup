#include "filler.h"

t_list		*ft_get_physical_sqr(t_obj input)
{
	int 	i;
	int 	j;
	t_co	*tmp;
	t_list	*head;
	char	**piece;

	head = NULL;
	i = 0;
	tmp = NULL;
	piece = input.piece;
	if (!(tmp = (t_co *)malloc(sizeof(t_co))))
		return (NULL);
	while (i < input.py)
	{
		j = 0;
		while (j < input.px)
		{
			if (piece[i][j] == '*')
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