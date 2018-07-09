#include "filler.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	t_obj	input;
	t_spot	**board;
	t_list	*head_piece;
	t_list	*head_board;
	// // t_co	toplace;

	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC);
	ft_init_struct(&input);
	while (get_next_line(0, &input.line))
	{
		ft_get_info(&input);
		free(input.line);
		if (input.isdone)
		{
			board = ft_makeboard(input);
			//ft_is_sqr_avilable(&board, input);
			head_piece = ft_get_physical_sqr(input);
			head_board = ft_get_available_move(board, input);
			// ft_lstprint_fd(head_piece, fd);
			ft_toplace(head_board, head_piece);
			//ft_place(toplace);
		}
	}
	input.i = 0;
	while (input.i < input.py)
	{
		ft_putendl_fd(input.piece[input.i], fd);
		input.i += 1;
	}
	// free(input.board);
	// free(input.piece);
	// free(player);
	return (1);
}