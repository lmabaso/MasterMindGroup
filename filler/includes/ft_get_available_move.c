#include "filler.h"

t_list	*ft_get_available_move(t_obj input)
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
			if (input.board[i][j] == input.mypiece)
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

int			ft_get_lowest(t_list *neighbours, t_spot **board)
{
	int		tmp;
	t_co 	*holder;

	holder = neighbours->content;
	tmp = board[holder->y][holder->x].score;
	while (neighbours)
	{
		holder = neighbours->content;
		if (board[holder->y][holder->x].score < tmp && board[holder->y][holder->x].score > 0)
			tmp = board[holder->y][holder->x].score;
		neighbours = neighbours->next;
	}
	return (tmp);
}

t_co	ft_find_low_cost(t_list *moves, t_spot **board)
{
	t_co	low_cost;
	t_co	*holder;
	int		tmp;
	int		a;

	holder = moves->content;
	low_cost.y = holder->y;
	low_cost.x = holder->x;
	tmp = ft_get_lowest(board[holder->y][holder->x].neighbours, board);
	while (moves)
	{
		holder = moves->content;
		a = ft_get_lowest(board[holder->y][holder->x].neighbours, board);
		if (a < tmp && a > 0)
		{
			low_cost.y = holder->y;
			low_cost.x = holder->x;
		} 
		moves = moves->next;
	}
	return (low_cost);
}