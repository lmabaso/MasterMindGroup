#include "filler.h"

int		ft_search_xb(int a, int x, t_obj input, t_co *tmp_left, t_co *tmp_right)
{
	int b;

	b = x;
	while (b < input.bx)
	{
		if (input.board[a][b] == input.oppiece)
		{
			ft_put_to_co(tmp_right, b, a);
			break ;
		}
		b++;
	}
	b = x;
	while (b >= 0)
	{
		if (input.board[a][b] == input.oppiece)
		{
			ft_put_to_co(tmp_left, b, a);
			break ;
		}
		b--;
	}
	return (0);
}

int		ft_search_xrl(t_co *tmp_left, t_co *tmp_right, t_co *found)
{
	if ((tmp_left->x != -42 && tmp_left->y != -42) &&
			(tmp_right->x == -42 && tmp_right->y == -42))
	{
		ft_put_to_co(found, tmp_left->x, tmp_left->y);
		return (1);
	}
	if ((tmp_right->x != -42 && tmp_right->y != -42) &&
			(tmp_left->x == -42 && tmp_left->y == -42))
	{
		ft_put_to_co(found, tmp_right->x, tmp_right->y);
		return (1);
	}
	return (0);
}

int		ft_search_x(int a, int x, t_obj input, t_co *found)
{
	t_co tmp_left;
	t_co tmp_right;
	t_co d;

	ft_put_to_co(&d, x, a);
	ft_put_to_co(&tmp_left, -42, -42);
	ft_put_to_co(&tmp_right, -42, -42);
	ft_search_xb(a, x, input, &tmp_left, &tmp_right);
	ft_search_xrl(&tmp_left, &tmp_right, found);
	if (tmp_right.x != -42 && tmp_right.y != -42
			&& tmp_left.x != -42 && tmp_left.y != -42)
	{
		if (getDistance(d, tmp_right) < getDistance(d, tmp_left))
			ft_put_to_co(found, tmp_right.x, tmp_right.y);
		else
			ft_put_to_co(found, tmp_left.x, tmp_left.y);
		return (1);
	}
	return (0);
}

void	ft_search_y(t_co *tmp_down, t_co *tmp_up, t_obj input, int y, int x)
{
	int a;

	a = y;
	while (a < input.by)
	{
		if (ft_search_x(a, x, input, tmp_down))
			break ;
		a++;
	}
	a = y;
	while (a >= 0)
	{
		if (ft_search_x(a, x, input, tmp_up))
			break ;
		a--;
	}
}

t_co	ft_find_close(int y, int x, t_obj input)
{
	t_co found;
	t_co d;
	t_co tmp_up;
	t_co tmp_down;

	ft_put_to_co(&found, 0, 0);
	ft_put_to_co(&d, x, y);
	ft_put_to_co(&tmp_up, -42, -42);
	ft_put_to_co(&tmp_down, -42, -42);
	ft_search_y(&tmp_down, &tmp_up, input, y, x);
	if (tmp_down.x != -42 && tmp_down.y != -42)
		if (tmp_up.x == -42 && tmp_up.y == -42)
			ft_put_to_co(&found, tmp_down.x, tmp_down.y);
	if (tmp_up.x != -42 && tmp_up.y != -42)
		if (tmp_down.x == -42 && tmp_down.y == -42)
			ft_put_to_co(&found, tmp_up.x, tmp_up.y);
	if (tmp_up.x != -42 && tmp_up.y != -42 &&
			tmp_down.x != -42 && tmp_down.y != -42)
	{
		if (getDistance(d, tmp_down) < getDistance(d, tmp_up))
			ft_put_to_co(&found, tmp_down.x, tmp_down.y);
		else
			ft_put_to_co(&found, tmp_up.x, tmp_up.y);
	}
	return (found);
}
