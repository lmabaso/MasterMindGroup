#include "filler.h"

void	ft_lstprint_fd(t_list *head, int fd)
{
	t_best	*tmp;

	while (head)
	{
		tmp =  head->content;
		ft_putnbr_fd(tmp->y, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(tmp->x, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(tmp->score, fd);
		ft_putchar_fd('\n', fd);
		head = head->next;
	}
}

t_co	*ft_lst_to_arr(t_list *head, int i)
{
	int count;
	t_co *array[i];
	t_co *tmp;

	count = 0;
	while (head)
	{
		tmp = head->content;
		array[count] = tmp;
		count++;
		head = head->next;
	}
	array[count] = NULL;
	return (*array);
}

t_co	ft_correct_point_b(t_co board, t_co *piece)
{
	t_co correct;

	correct.y = board.y - piece->y;
	correct.x = board.x - piece->x;
	return (correct);
}

void	ft_play(t_co toplace)
{
	ft_putnbr(toplace.y);
	ft_putchar(' ');
	ft_putnbr(toplace.x);
	ft_putchar('\n');
}

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
			if (input.piece[i][j] == '*' && input.board[k][l] == input.mypiece)
			{
				overlap++;
			}
			if (input.board[k][l] == input.oppiece)
				return (0);
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

void	ft_toplace(t_co board, t_obj input, t_spot **heat)
{
	t_co	toplace;
	t_co	tmp_piece;
	t_best  move;
	t_list	*valid;
	int		i;
	int		j;
	int		score;
	t_list	*tmp_valid;
	t_best	*lowest;
	t_best	*tmp;
	
	i = 0;
	tmp_piece.y = 0;
	tmp_piece.x = 0;
	while (i < input.py)
	{
		j = 0;
		while (j < input.px)
		{
			tmp_piece.y = i;
			tmp_piece.x = j;
			toplace = ft_correct_point_b(board, &tmp_piece);
			score = 0;
			if (ft_check_overlap(toplace, input, &score, heat) == 1)
			{
				move.score = score;
				move.x = j;
				move.y = i;
				ft_lstadd(&valid, ft_lstnew(&move, sizeof(t_best)));
			}
			j++;
		}
		i++;
	}

	tmp_valid = valid;
	lowest = tmp_valid->content;
	while (tmp_valid)
	{
		tmp = tmp_valid->content;
		if (tmp->score < lowest->score)
			lowest = tmp;
		tmp_valid = tmp_valid->next;
	}
	tmp_piece.y = lowest->y;
	tmp_piece.x = lowest->x;
	toplace = ft_correct_point_b(board, &tmp_piece);

	ft_play(toplace);
	// return (valid);
}