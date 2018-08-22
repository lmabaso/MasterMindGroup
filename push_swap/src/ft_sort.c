#include "../includes/push_swap.h"

int		ft_b_rot(int len, int pos, char **rot)
{	
    (pos > len / 2) ? ft_strcpy(*rot, "rrb") : ft_strcpy(*rot, "rb");
	return (((pos > len / 2) && (len > 2)) ? len - pos : pos);
}

int		ft_a_rot(int len, int pos, char **rot)
{	
    (pos > len / 2) ? ft_strcpy(*rot, "rra") : ft_strcpy(*rot, "ra");
	return (((pos > len / 2) && (len > 2)) ? len - pos : pos);
}

static int  find_place_in_b(t_list **b, int elem, char *rot)
{
	int     i;
	int     place;
    int     len;
    t_list  *tmp;

	i = 1;
	place = 0;
    tmp = *b;
	len = ft_lstlen(*b);
    while (i < len)
    {
        if (elem < ft_first(&tmp) && elem > ft_second(&tmp))
        {
            place = i;
            break ;
        }
        tmp = tmp->next;
        i++;
    }
	return (ft_b_rot(len, place, &rot));
}

int		find_place_in_a(t_list **a, int elem, char *rot)
{
	int i;
	int place;
    int len;
    t_list *tmp;

    len = ft_lstlen(*a);
	i = 1;
	place = 0;
    tmp = *a;
	if (elem > ft_max(a) || elem < ft_min(a))
		place = ft_pos(a, ft_min(a));
	else
		while (i < len)
		{
			if (elem > ft_first(&tmp) && elem < ft_second(&tmp))
			{
				place = i;
				break ;
			}
            tmp = tmp->next;
			i++;
		}
	return (ft_a_rot(len, place, &rot));
}

static int		find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if ((ft_strequ(moves->a_rot, "rra") && (ft_strequ(moves->b_rot , "rrb"))) || (ft_strequ(moves->a_rot, "ra") && (ft_strequ(moves->b_rot , "rb"))))
	{
		common = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (common)
		{
			ft_strcpy(moves->common_rot, moves->a_rot);
			moves->common_rot[ft_strlen(moves->common_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

static t_moves	*calc_moves_from_a_to_b(t_list **a, t_list **b, int pos)
{
	t_moves *moves;

	moves = ft_memalloc(sizeof(t_moves));
	moves->a_rot = ft_strnew(3);
	moves->b_rot = ft_strnew(3);
	moves->common_rot = ft_strnew(3);
	moves->elem = ft_at_index(a, pos);
	moves->a_moves = ft_a_rot(ft_lstlen(*a), pos, &moves->a_rot);
	moves->b_moves = find_place_in_b(b, ft_at_index(a, pos), moves->b_rot);
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves;
	return (moves);
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rot);
	free(moves->b_rot);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}

t_moves			*best_way_from_a_to_b(t_list **a, t_list **b)
{
	int         i;
	t_moves     *best_move;
	t_moves		*moves;
    t_list      *tmp;

	i = 0;
    tmp = *a;
	while (tmp)
	{ 
		moves = calc_moves_from_a_to_b(a, b, i);
		if (!i)
			best_move = moves;
		if (best_move->total > moves->total)
		{
			free_moves(best_move);
			best_move = moves;
		}
		else if (i)
			free_moves(moves);
		i++;
        tmp = tmp->next;
	}
	return (best_move);
}

static void	process_moves(t_moves *best_move, t_list **a, t_list **b)
{
	while (best_move->a_moves)
	{
		ft_update(a, b,best_move->a_rot);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
        ft_update(a, b, best_move->b_rot);
		best_move->b_moves--;
	}
}

void	place_smallest_first_a(t_list **a, t_list **b)
{
	register int min_index;

	min_index = ft_pos(a, ft_min(a));
	if (min_index <= ft_lstlen(*a) / 2)
		while (min_index--)
            ft_update(a, b, "ra");
	else
		while ((ft_lstlen(*a) - min_index) > 0)
		{
            ft_update(a, b, "rra");
			min_index++;
		}
}

static void	insert_back_in_a(t_list **a, t_list **b)
{
	int     rots;
	char    *rot_type;

	rots = 0;
	rot_type = ft_strnew(3);
	while (*b)
	{
		rots = find_place_in_a(a, ft_first(b), rot_type);
		while (rots > 0)
		{
			ft_update(a, b, rot_type);
			rots--;
		}
        ft_update(a, b, "pa");
	}
	place_smallest_first_a(a, b);
	free(rot_type);
}

char		*ft_sort(t_list **a, t_list **b)
{
	t_moves *best_move;

	while (ft_lstlen(*b) != 2)
	{
		(ft_first(a) == ft_max(a)) ? ft_update(a, b, "rra") : ft_update(a, b, "pb");
	}
	while (ft_lstlen(*a) > 2)
	{
		best_move = best_way_from_a_to_b(a, b);
		while (best_move->common_moves)
		{
            ft_update(a, b, best_move->common_rot);
			best_move->common_moves--;
		}
		process_moves(best_move, a, b);
        ft_update(a, b, "pb");
		free_moves(best_move);
	}
	insert_back_in_a(a, b);
    return ("ok");
}