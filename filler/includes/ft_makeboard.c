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

t_co		ft_find_close(int y, int x, t_obj input)
{
	t_co found;
	int i;
	int a;
	int b;

	i = 0;
	found.y = 0;
	found.x = 0;
	while (i < input.bx * input.by)
	{
		a = y;
		while (a < input.by)
		{
			b = x;
			while (b < input.bx)
			{
				if (input.board[a][b] == input.oppiece)
				{
					found.y = a;
					found.x = b;
					return (found);
				}
				b++;
			}
			b = x;
			while (b > 0)
			{
				if (input.board[a][b] == input.oppiece)
				{
					found.y = a;
					found.x = b;
					return (found);
				}
				b--;
			}
			a++;
		}
		a = y;
		while (a > 0)
		{
			b = x;
			while (b < input.bx)
			{
				if (input.board[a][b] == input.oppiece)
				{
					found.y = a;
					found.x = b;
					return (found);
				}
				b++;
			}
			b = x;
			while (b > 0)
			{
				if (input.board[a][b] == input.oppiece)
				{
					found.y = a;
					found.x = b;
					return (found);
				}
				b--;
			}
			a--;
		}	
		i++;
	}
	return (found);
}

t_spot		**ft_makeboard(t_obj input)
{
	t_spot	**board;
	t_co	tmp;
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
			if (board[i][j].state == '.')
				board[i][j].score = 0;
			if (board[i][j].state == input.mypiece)
				board[i][j].score = -2;
			if (board[i][j].state == input.oppiece)
				board[i][j].score = -1;
			j++;
		}
		i++;
	}
	i = 0;
	int a;
	int b;
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			if (board[i][j].score == 0)
			{
				tmp = ft_find_close(i, j, input);
				a = -(tmp.y - i * tmp.y - i);
				b = -(tmp.x - j * tmp.x - j);
				board[i][j].score = a + b;
			}
			j++;
		}
		i++;
	}
	// 	i = 0;
	// 	j = 0;
	// 	a++;
	// }
return (board);
}
