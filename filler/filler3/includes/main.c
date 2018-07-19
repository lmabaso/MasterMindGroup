#include "filler.h"
#include <fcntl.h>

int		ft_best_move(t_list *moves, t_obj *input)
{
	t_best	*tmp;
	t_co	eval;
	t_list	*lst_opt;
	t_best	optimal;

	input->i = 0;
	lst_opt = NULL;
	if (moves == NULL)
		return (0);
	if (moves == NULL)
		return (0);
	// MergeSort(&moves);
	while (moves)
	{
		tmp = moves->content;
		ft_best_to_co(&eval, *tmp);
		if (ft_toplace(eval, *input, &optimal))
			ft_lstadd(&lst_opt, ft_lstnew(&optimal, sizeof(t_best)));
		moves = moves->next;
	}
	if (lst_opt != NULL)
	{
		MergeSort(&lst_opt);
		tmp = lst_opt->content;
		ft_best_to_co(&input->bestmove, *tmp);

		if (moves != NULL)
			deleteList(&moves);
		if (lst_opt != NULL)
			deleteList(&lst_opt);
		return (1);
	}
	if (moves != NULL)
		deleteList(&moves);
	if (lst_opt != NULL)
		deleteList(&lst_opt);
	return (0);
}

int		main(void)
{
	int		fd;
	t_obj	*input;
	t_list	*moves;

	moves = NULL;
	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);
	if (!(input = ft_memalloc(sizeof(t_obj))))
		return (-1);
	ft_init_struct(input);
	while (get_next_line(0, &input->line) > 0)
	{
		ft_get_info(input);
		if (input->isdone)
		{
			input->aboard = ft_makeboard(*input);
			input->realpiece = ft_get_physical_sqr(*input);
			
			if (ft_get_all_moves(input))
				if (ft_best_move(ft_lowcost(input), input))
					ft_play(input->bestmove);
				else
					ft_play(input->bestmove);
			else
				ft_play(input->bestmove);
			ft_makezero(input);
		}
	}
	if (input->line)
			free(input->line);
	free(input);
	
	return (1);
}
