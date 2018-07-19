#include "filler.h"

void	ft_put_in_best(t_best *best, int x, int y, int score)
{
	best->x = x;
	best->y = y;
	best->score = score;
}

void	ft_put_to_co(t_co *co, int x, int y)
{
	co->x = x;
	co->y = y;
}

void	ft_co_to_best(t_best *best, t_co co)
{
	best->x = co.x;
	best->y = co.y;
	best->score = 0;
}

void	ft_best_to_co(t_co *co, t_best best)
{
	co->x = best.x;
	co->y = best.y;
}
