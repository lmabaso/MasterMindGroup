#include "filler.h"

int		ft_check_overlap(t_co board, t_obj input, int *score, t_spot **heat)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		overlap;
	int		count;

	count = 0;
	overlap = 0;
	i = 0;
	k = board.y;
	while (i < input.py)
	{
		l = board.x;
		j = 0;
		while (j < input.px)
		{
			if (l > input.bx - 1 && input.piece[i][j] == '*')
				return (0);
			if (l < 0 && input.piece[i][j] == '*')
				return (0);
			if (k > input.by - 1 && input.piece[i][j] == '*')
				return (0);
			if (k < 0 && input.piece[i][j] == '*')
				return (0);
			if (input.piece[i][j] == '*' && input.board[k][l] == input.oppiece)
				return (0);
			if (input.piece[i][j] == '*' && input.board[k][l] == input.mypiece)
				overlap++;
			if (input.piece[i][j] == '*')
				count += heat[k][l].score;
			l++;
			j++;
		}
		i++;
		k++;
	}
	*score = count;
	return (overlap);
}

t_list	*ft_valid_moves(t_co board, t_obj input, t_spot **heat)
{
	t_list	*valid;
	t_best  move;
	t_co	tmp_piece;
	t_co	toplace;
	int		i;
	int		j;
	int		score;

	valid = NULL;
	ft_put_to_co(&tmp_piece, 0, 0);
	i = 0;
	while (i < input.py)
	{
		j = 0;
		while (j < input.px)
		{
			ft_put_to_co(&tmp_piece, j, i);
			toplace = ft_correct_point_b(board, &tmp_piece);
			score = 0;
			if (ft_check_overlap(toplace, input, &score, heat) == 1)
			{
				ft_put_in_best(&move, j, i, score);
				ft_lstadd(&valid, ft_lstnew(&move, sizeof(t_best)));
			}
			j++;
		}
		i++;
	}
	return (valid);
}

int		ft_toplace(t_co board, t_obj input, t_spot **heat, t_co *bestmove)
{
	t_co	tmp_piece;
	t_list	*valid;
	t_best	*lowest;
	t_best	*tmp;

	ft_put_to_co(bestmove, -42, -42);
	valid = ft_valid_moves(board, input, heat);
	if (ft_lstlen(valid) == 0)
		return (0);
	lowest = valid->content;
	while (valid)
	{
		tmp = valid->content;
		if (tmp->score < lowest->score)
			lowest = tmp;
		valid = valid->next;
	}
	ft_best_to_co(&tmp_piece, *lowest);
	*bestmove = ft_correct_point_b(board, &tmp_piece);
	if (bestmove->x == -42 || bestmove->y == -42)
		return (0);
	return (1);
}
