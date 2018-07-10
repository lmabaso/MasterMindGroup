#include "filler.h"
#include <fcntl.h>

void	ft_lstprint_fd(t_list *head, int fd);

int		main(void)
{
	int		fd;
	t_obj	*input;
	t_spot	**board;
	t_list	*head_board;
	t_list	*toplace;

	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);
	if (!(input = ft_memalloc(sizeof(t_obj))))
		return (-1);
	ft_init_struct(input);
	get_next_line(0, &input->line);
	ft_get_info(input);
	while (1)
	{
		get_next_line(0, &input->line);
		ft_get_info(input);
		if (input->isdone)
		{
			board = ft_makeboard(*input);
			head_board = ft_get_available_move(*input);
			toplace = ft_find_low_cost(head_board, board);
			//ft_toplace(toplace, *input, board);
			//ft_place(toplace);
			input->isdone = 0;
			input->j = 0;
			input->i = 0;
		}
		//if (input->gameover == 1)
		//	break ;
	}
	// free(input.board);
	// free(input.piece);
	//free(input);
	return (1);
}