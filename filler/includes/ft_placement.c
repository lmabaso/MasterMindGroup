#include "filler.h"

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