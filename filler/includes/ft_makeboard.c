#include "filler.h"
#include <math.h>

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

int			ft_search_x(int a, int x, t_obj input, t_co *found)
{
	int b;
	t_co tmp_left;
	t_co tmp_right;
	t_co d;

	b = x;
	ft_put_to_co(&d, x, a);
	ft_put_to_co(&tmp_left, -42, -42);
	ft_put_to_co(&tmp_right, -42, -42);
	while (b < input.bx)
	{
		if (input.board[a][b] == input.oppiece)
		{
			ft_put_to_co(&tmp_left, b, a);
			break ;
		}
		b++;
	}
	b = x;
	while (b > 0)
	{
		if (input.board[a][b] == input.oppiece)
		{
			ft_put_to_co(&tmp_left, b, a);
			break ;
		}
		b--;
	}
	if (tmp_left.x != -42 && tmp_left.y != -42)
		if (tmp_right.x == -42 && tmp_right.y == -42)
		{
			ft_put_to_co(found, tmp_left.x, tmp_left.y);
			return (1);
		}
	if (tmp_right.x != -42 && tmp_right.y != -42)
		if (tmp_left.x == -42 && tmp_left.y == -42)
		{
			ft_put_to_co(found, tmp_right.x, tmp_right.y);
			return (1);
		}
	
	if (tmp_right.x != -42 && tmp_right.y != -42 && tmp_left.x != -42 && tmp_left.y != -42)
	{
		if (getDistance(d, tmp_right) < getDistance(d, tmp_left))
			ft_put_to_co(found, tmp_right.x, tmp_right.y);
		else
			ft_put_to_co(found, tmp_left.x, tmp_left.y);
		return (1);
	}
	return (0);
}

t_co		ft_find_close(int y, int x, t_obj input)
{
	t_co found;
	int i;
	int a;
	t_co d;
	t_co tmp_up;
	t_co tmp_down;
	// int b;

	i = 0;
	ft_put_to_co(&found, 0, 0);
	ft_put_to_co(&d, x, y);
	ft_put_to_co(&tmp_up, -42, -42);
	ft_put_to_co(&tmp_down, -42, -42);

	a = y;
	while (a < input.by)
	{
		if (ft_search_x(a , x, input, &found))
		{
			ft_put_to_co(&tmp_down, found.x, found.y);
			break ;
		}
		a++;
	}
	a = y;
	while (a > 0)
	{
		if (ft_search_x(a , x, input, &found))
		{
			ft_put_to_co(&tmp_up, found.x, found.y);
			break ;
		}
		a--;
	}	
	if (tmp_down.x != -42 && tmp_down.y != -42)
	{
		if (tmp_up.x == -42 && tmp_up.y == -42)
			ft_put_to_co(&found, tmp_down.x, tmp_down.y);
	}
	else if (tmp_up.x != -42 && tmp_up.y != -42)
	{
		if (tmp_down.x == -42 && tmp_down.y == -42)
			ft_put_to_co(&found, tmp_up.x, tmp_up.y);
	}
	else if (tmp_up.x != -42 && tmp_up.y != -42 && tmp_down.x != -42 && tmp_down.y != -42)
	{
		if (getDistance(d, tmp_down) < getDistance(d, tmp_up))
			ft_put_to_co(&found, tmp_down.x, tmp_down.y);
		else
			ft_put_to_co(&found, tmp_up.x, tmp_up.y);
	}		
	return (found);
}

double	ft_sqrt(double num)
{
	int i;

	i = 0;
	if (num == 0 || num == 1)
		return (num);
	while (i < num)
	{
		i++;
		num *=i;
	}
	return (i - 1);
}

double getDistance(t_co a, t_co b)
{
	double distance;
	distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) * (a.y-b.y));
	return (distance);
}

t_spot		**ft_makeboard(t_obj input)
{
	t_spot	**board;
	t_co	tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(board = (t_spot **)malloc(sizeof(t_spot *) * input.by)))
		return (NULL);
	while (i < input.by)
	{
		if (!(board[i] = (t_spot *)malloc(sizeof(t_spot) * input.bx)))
			return (NULL);
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
	t_co tmp1;
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			if (board[i][j].score == 0)
			{
				tmp1.x = j;
				tmp1.y = i;
				tmp = ft_find_close(i, j, input);
				board[i][j].score = (int)getDistance(tmp, tmp1);
			}
			j++;
		}
		i++;
	}
	return (board);
}
