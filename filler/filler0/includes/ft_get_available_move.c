#include "filler.h"

int			ft_get_available_move(t_obj input, t_list **head)
{
	int		i;
	int		j;
	t_co	tmp;

	i = 0;
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			if (input.board[i][j] == input.mypiece)
			{
				ft_put_to_co(&tmp, j, i);
				ft_lstadd(head, ft_lstnew(&tmp, sizeof(t_co)));
			}
			j++;
		}
		i++;
	}
	if (ft_lstlen(*head))
		return (1);
	return (0);
}

int			ft_get_lowest(t_list *neighbours, t_spot **board)
{
	int		tmp;
	t_co	*holder;
	t_list	*t;

	tmp = 0;
	t = neighbours;
	while (t)
	{
		holder = t->content;
		if ((tmp = board[holder->y][holder->x].score) > 0)
			break ;
		t = t->next;
	}
	while (neighbours)
	{
		holder = neighbours->content;
		if (tmp == 0 || tmp == -2)
			tmp = board[holder->y][holder->x].score;
		if (board[holder->y][holder->x].score < tmp)
			if (board[holder->y][holder->x].score > 0)
				tmp = board[holder->y][holder->x].score;
		neighbours = neighbours->next;
	}
	return (tmp);
}

t_list		*ft_lowcost(t_list *moves, t_spot **board)
{
	t_list	*head;
	t_best	low_cost;
	t_co	*holder;

	head = NULL;
	holder = moves->content;
	ft_co_to_best(&low_cost, *holder);
	low_cost.score = ft_get_lowest(board[holder->y][holder->x].neighbours, board);
	while (moves)
	{
		holder = moves->content;
		ft_co_to_best(&low_cost, *holder);
		low_cost.score = ft_get_lowest(board[holder->y][holder->x].neighbours, board);
		if (low_cost.score > 0)
			ft_lstadd(&head, ft_lstnew(&low_cost, sizeof(t_best)));
		moves = moves->next;
	}
	return (head);
}
