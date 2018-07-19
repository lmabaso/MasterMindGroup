#include "filler.h"

void    ft_test_show_heat(t_spot **board, int fd, t_obj *input)
{
    int i;
	int j;

    i = 0;
    while(i < input->by)
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
    ft_putchar_fd('\n', fd);
    ft_putendl_fd(input->player, fd);
}

void    ft_print_co(t_co *tmp, int fd)
{
    ft_putnbr_fd(tmp->y, fd);
    ft_putchar_fd(' ', fd);
    ft_putnbr_fd(tmp->x, fd);
    ft_putchar_fd('\n', fd);
}

void	ft_lstprint_fd(t_list *head, int fd)
{
	t_best	*tmp;

	while (head)
	{
		tmp =  head->content;
		ft_putnbr_fd(tmp->y, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(tmp->x, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(tmp->score, fd);
		ft_putchar_fd('\n', fd);
		head = head->next;
	}
}