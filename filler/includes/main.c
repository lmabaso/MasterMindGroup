#include "filler.h"
#include <fcntl.h>

void	ft_lstprint_fd(t_list *head, int fd);

void	ft_lstdestroy(t_list *del)
{
	if (del)
	{
		while (del){
		ft_memdel((void **)del);
		del = del->next;
		}
	}
}

t_list	*insertion_sort(t_list *head)
{
	t_list *x;
	t_list *y;
	t_list *z;
	t_best *a;
	t_best *b;
	t_best *c;

	x = head;
	head = NULL;
	while (x != NULL)
	{
		z = x;
		x = x->next;
		if (head != NULL)
		{
			a = z->content;
			b = head->content;
			if (a->score > b->score)
			{
				y = head;
				c = y->next->content;
				while ((y->next != NULL) && (a->score > c->score))
				{
					y = y->next;
				}
				z->next = y->next;
				y->next = z;
			}
			else
			{
				z->next = head;
				head = z;
			}
		}
		else
		{
			z->next = NULL;
			head = z;
		}
	}
	return (head);
}

t_co	ft_make_best_move(t_list *moves, t_obj input, t_spot **board)
{
	t_co	bestmove;
	t_best	*tmp;
	t_co	eval;

	ft_put_to_co(&bestmove, -42, -42);
	while (moves)
	{
		tmp = moves->content;
		ft_best_to_co(&eval, *tmp);
		if (ft_toplace(eval, input, board, &bestmove))
			return (bestmove);
		moves = moves->next;
	}
	return (bestmove);
}

int		main(void)
{
	int		fd;
	t_obj	*input;
	t_spot	**board;
	t_list	*head_board;
	t_list	*toplace;
	t_list 	*order;
	t_co	bestmove;
	int i;
	int j;

	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);
	if (!(input = ft_memalloc(sizeof(t_obj))))
		return (-1);
	ft_init_struct(input);
	while (get_next_line(0, &input->line))
	{
		ft_get_info(input);
		if (input->isdone)
		{
			board = ft_makeboard(*input);
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
			head_board = ft_get_available_move(*input);
			toplace = ft_find_low_cost(head_board, board);
			order = insertion_sort(toplace);
			bestmove = ft_make_best_move(order, *input, board);
			ft_play(bestmove);
			ft_lstdestroy(head_board);
			ft_lstdestroy(order);
			ft_lstdestroy(toplace);
			input->isdone = 0;
			input->j = 0;
			input->i = 0;
		}
	}
	//free(input);
	return (1);
}