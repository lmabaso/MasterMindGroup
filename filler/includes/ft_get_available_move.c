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
			if (input.board[i][j] == input.mypiece || input.board[i][j] == input.mypiece + 32)
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

t_list	*ft_find_low_cost(t_list *moves, t_spot **board)
{
	t_list	*head;
	t_best	*low_cost;
	t_co	*holder;

	head = NULL;
	holder = moves->content;
	low_cost->y = holder->y;
	low_cost->x = holder->x;
	while (moves)
	{
		holder = moves->content;
		low_cost->score = ft_get_lowest(board[holder->y][holder->x].neighbours, board);
		low_cost->y = holder->y;
		low_cost->x = holder->x;
		ft_lstadd(&head, ft_lstnew(low_cost, sizeof(t_best)));
		moves = moves->next;
	}
	return (head);
}