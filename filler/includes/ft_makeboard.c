#include "filler.h"

int 	ft_is_available(t_list *neighbours, t_obj input, int y, int x)
{
	t_co	*co;
	int i;
	int count;

	count = 0;
	i = ft_lstlen(neighbours);
	if (input.board[y][x] == input.mypiece)
	{
		if (i == 4)
		{
			while (neighbours)
			{
				co = neighbours->content;
				if (input.board[co->y][co->x] == '.')
					return (1);
				neighbours = neighbours->next;
			}
		}
		else if (i == 3)
		{
			while (neighbours)
			{
				co = neighbours->content;
				if (input.board[co->y][co->x] == '.')
					return (1);
				neighbours = neighbours->next;
			}
		}
		else if (i == 2)
		{
			while (neighbours)
			{
				co = neighbours->content;
				if (input.board[co->y][co->x] == '.')
					return (1);
				neighbours = neighbours->next;
			}
		}
	}
	return (0);
}

t_spot		**ft_makeboard(t_obj input)
{
	t_spot	**board;
	int i;
	int j;

	i = 0;
	j = 0;
	board = (t_spot **)malloc(sizeof(t_spot *) * input.by);
	while (i < input.by)
	{
		board[i] = (t_spot *)malloc(sizeof(t_spot) * input.bx);
		i++;
	}
	i = 0;
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			board[i][j].neighbours = ft_get_neighbours(i, j, input);
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].state = input.board[i][j];
			board[i][j].available = ft_is_available(board[i][j].neighbours, input, i, j);
			j++;
		}
		i++;
	}
	return (board);
}
