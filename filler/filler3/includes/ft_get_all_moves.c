#include "filler.h"

int			ft_get_all_moves(t_obj *input)
{
	t_co	tmp;

	input->i = 0;
	while (input->i < input->by)
	{
		input->j = 0;
		while (input->j < input->bx)
		{
			if (input->board[input->i][input->j] == input->mypiece
			|| input->board[input->i][input->j] == ft_tolower(input->mypiece))
			{
				ft_put_to_co(&tmp, input->j, input->i);
				ft_lstadd(&input->moves, ft_lstnew(&tmp, sizeof(t_co)));
			}
			input->j++;
		}
		input->i++;
	}
	if (ft_lstlen(input->moves))
		return (1);
	return (0);
}

int			ft_get_lowest(t_list *neighbours, t_obj *input)
{
	int		tmp;
	t_co	*coordinate;
	t_list	*t;

	tmp = 0;
	if (neighbours != NULL)
	{
		t = neighbours;
		while (neighbours)
		{
			coordinate = neighbours->content;
			if (tmp == 0 || tmp == -2 || tmp == -1)
				tmp = input->aboard[coordinate->y][coordinate->x].score;
			if (input->aboard[coordinate->y][coordinate->x].score < tmp)
				if (input->aboard[coordinate->y][coordinate->x].score > 0)
					tmp = input->aboard[coordinate->y][coordinate->x].score;
			neighbours = neighbours->next;
		}
	}
	return (tmp);
}

t_list		*ft_lowcost(t_obj *input)
{
	t_list	*head;
	t_best	low_cost;
	t_co	*coordinate;
	t_list  *moves;

	head = NULL;
	moves = input->moves;
	coordinate = moves->content;
	ft_co_to_best(&low_cost, *coordinate);
	low_cost.score = ft_get_lowest(input->aboard[coordinate->y][coordinate->x].neighbours, input);
	while (moves)
	{
		coordinate = moves->content;
		ft_co_to_best(&low_cost, *coordinate);
		low_cost.score = ft_get_lowest(input->aboard[coordinate->y][coordinate->x].neighbours, input);
		if (low_cost.score > 0)
			ft_lstadd(&head, ft_lstnew(&low_cost, sizeof(t_best)));
		moves = moves->next;
	}
	// if (moves)
		// ft_lstfree(moves);
	return (head);
}
