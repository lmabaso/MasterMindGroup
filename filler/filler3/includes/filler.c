#include "filler.h"

int		ft_check_overlap(t_co board, t_obj input, int *score)
{
	int		overlap;
	int		count;
	t_co	*tmp;
	t_co	superpose;

	count = 0;
	overlap = 0;
	while (input.realpiece)
	{
		tmp = input.realpiece->content;
		ft_put_to_co(&superpose, board.x + tmp->x, board.y + tmp->y);
		if (superpose.x > input.bx - 1 || superpose.x < 0 )
			return (0);
		if (superpose.y > input.by - 1 || superpose.y < 0 )
			return (0);
		if (ft_toupper(input.board[superpose.y][superpose.x]) == input.oppiece)
			return (0);
		if (ft_toupper(input.board[superpose.y][superpose.x]) == input.mypiece)
			overlap++;
		count += input.aboard[superpose.y][superpose.x].score;
		input.realpiece = input.realpiece->next;
	}
	*score = count;
	return (overlap);
}

t_list	*ft_valid_moves(t_co board, t_obj input)
{
	t_list	*valid;
	t_best  move;
	t_co	tmp;
	int		score;

	valid = NULL;
	ft_put_to_co(&tmp, 0, 0);
	input.i = 0;
	while (input.i < input.py)
	{
		input.j = 0;
		while (input.j < input.px)
		{
			ft_put_to_co(&tmp, input.j, input.i);
			score = 0;
			if (ft_check_overlap(ft_relative_b(board, &tmp), input, &score) == 1)
			{
				ft_put_in_best(&move, input.j, input.i, score);
				ft_lstadd(&valid, ft_lstnew(&move, sizeof(t_best)));
			}
			input.j++;
		}
		input.i++;
	}
	return (valid);
}

int		ft_toplace(t_co board, t_obj input, t_best *optimal)
{
	t_co	tmp_piece;
	t_list	*valid;
	t_best	*lowest;
	t_best	*tmp;
	t_co bestmove;

	ft_put_to_co(&bestmove, 0, 0);
	if (!(valid = ft_valid_moves(board, input)))
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
	bestmove = ft_relative_b(board, &tmp_piece);
	ft_co_to_best(optimal, bestmove);
	optimal->score = lowest->score;
	if (valid != NULL)
		ft_lstfree(valid);
	return (1);
}
