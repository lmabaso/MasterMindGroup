#include "filler.h"
#include <fcntl.h>

void	ft_lstprint_fd(t_list *head, int fd);

int		main(void)
{
	int		fd;
	t_obj	*input;
	t_spot	**board;
	t_list	*head_piece;
	t_list	*head_board;
    int i;
    int j;
	t_co	toplace;

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
			//ft_is_sqr_avilable(&board, input);
			head_piece = ft_get_physical_sqr(*input);
			head_board = ft_get_available_move(*input);

			i = 0;
            while (i < input->by)
            {
                j = 0;
                while (j < input->bx)
                {
                    ft_putnbr_fd(board[i][j].score, fd);
                    if (board[i][j].score < 10 && board[i][j].score > 0)
						ft_putchar_fd(' ', fd);
					ft_putchar_fd(' ', fd);
                    j++;
                }
                ft_putchar_fd('\n', fd);
                i++;
            }

			toplace = ft_find_low_cost(head_board, board);
			
			//ft_lstprint_fd(ft_toplace(toplace, *input, board), fd);
			
			//ft_place(toplace);

			input->isdone = 0;
		}
		if (input->gameover == 1)
			break ;
	}
	// free(input.board);
	// free(input.piece);
	//free(input);
	return (1);
}