#include "filler.h"
#include <fcntl.h>


void	ft_lstprint_fd(t_list *head, int fd)
{
	t_co	*tmp;

	while (head)
	{
		tmp =  head->content;
		ft_putnbr_fd(tmp->y, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(tmp->x, fd);
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

t_co	ft_correct_point_b(t_co board, t_co piece)
{
	t_co correct;

	correct.y = board.y - piece.y;
	correct.x = board.x - piece.x;
	return (correct);
}

// int 	ft_overlap(t_obj input, t_co board, t_co piece)
// {
	
// }

// int 	ft_ispossible(t_obj input, t_co board, t_co piece, t_co *whole_piece)
// {
// 	int i;
// 	int x;

// 	i = 0;
// 	x = 0;
// 	while (whole_piece[i])
// 		i++;
// 	while (x < i)
// 	{

// 	}
// }

// t_co	ft_find_posible_move(t_obj input, t_co *board, t_co *piece)
// {
	
// }
void	ft_play(t_co toplace)
{
	ft_putnbr(toplace.y);
	ft_putchar(' ');
	ft_putnbr(toplace.x);
	ft_putchar('\n');
}

void	ft_toplace(t_list *board, t_list *piece)
{
	t_co	*piece_arr;
	t_co	*board_arr;
	t_co	toplace;

	piece_arr = ft_lst_to_arr(piece, ft_lstlen(piece));
	board_arr = ft_lst_to_arr(board, ft_lstlen(board));

	toplace = ft_correct_point_b(board_arr[0], piece_arr[0]);
	ft_play(toplace);

	// return (toplace);
}




