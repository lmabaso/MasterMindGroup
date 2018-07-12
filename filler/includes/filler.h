#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	object
{
	int			fd;
	int			bx;
	int			by;
	int			px;
	int			py;
	int 		i;
	int 		j;
	int			isdone;
	int			ko;
	int			gameover;
	char 		*player;
	char		*line;
	char		mypiece;
	char		oppiece;
	char		**board;
	char		**piece;
}				t_obj;

typedef	struct	status
{
	char		*mpieces;
	char 		*opieces;
}				t_status;

typedef	struct	coordinates
{
	int			x;
	int			y;
}				t_co;

typedef struct	bestmove
{
	int			x;
	int			y;
	int			score;
}				t_best;

typedef struct	spot
{
	int			x;
	int			y;
	t_list		*neighbours;
	char		state;
	int 		available;
	int			score;
}				t_spot;

t_spot		**ft_makeboard(t_obj input);

void		ft_play(t_co toplace);
void		ft_put_in_best(t_best *best, int x, int y, int score);
void		ft_put_to_co(t_co *co, int x, int y);
void		ft_co_to_best(t_best *best, t_co co);
void		ft_best_to_co(t_co *co, t_best best);
void		ft_get_info(t_obj *input);
void		ft_init_struct(t_obj *input);

double getDistance(t_co a, t_co b);

t_co		*ft_lst_to_arr(t_list *head, int i);
t_co		ft_correct_point_b(t_co board, t_co *piece);
int			ft_toplace(t_co board, t_obj input, t_spot **heat, t_co *bestmove);

t_list		*ft_get_opponent_pieces(t_obj input);
t_list		*ft_find_low_cost(t_list *moves, t_spot **board);
t_list		*ft_valid_moves(t_co board, t_obj input, t_spot **heat);
t_list		*ft_get_neighbours(int c, int r, t_obj input);
t_list		*ft_get_available_move(t_obj input);
t_list		*ft_get_physical_sqr(t_obj input);

int			ft_get_lowest(t_list *neighbours, t_spot **board);

#endif
