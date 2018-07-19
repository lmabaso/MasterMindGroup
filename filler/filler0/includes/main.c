#include "filler.h"
#include <fcntl.h>

int		ft_best_move(t_list *moves, t_obj input, t_spot **board, t_co *best)
{
	t_best	*tmp;
	t_co	eval;

	ft_put_to_co(best, -42, -42);
	moves = insertion_sort(moves);
	while (moves)
	{
		tmp = moves->content;
		ft_best_to_co(&eval, *tmp);
		if (ft_toplace(eval, input, board, best))
		{
			if (best->x != -42 && best->y != -42)
				return (1);
		}
		moves = moves->next;
	}
	return (0);
}

void	ft_makezero(t_obj *input)
{
	input->isdone = 0;
	input->j = 0;
	input->i = 0;
}

int		main(void)
{
	int		fd;
	t_obj	*input;
	t_spot	**board;
	t_list	*moves;
	t_co	bestmove;

	moves = NULL;
	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);
	if (!(input = ft_memalloc(sizeof(t_obj))))
		return (-1);
	ft_init_struct(input);
	while (get_next_line(0, &input->line) > 0)
	{
		ft_get_info(input);
		//ft_putendl_fd("faint", fd);
		if (input->isdone)
		{
			board = ft_makeboard(*input);
			//ft_test_show_heat(board, fd, input);
			if (ft_get_available_move(*input, &moves) == 0)
				break ;
			if (ft_best_move(ft_lowcost(moves, board), *input, board, &bestmove))
				ft_play(bestmove);
			ft_makezero(input);
		}
	}
	free(input);
	return (1);
}
