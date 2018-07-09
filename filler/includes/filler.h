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

typedef struct	spot
{
	int			x;
	int			y;
	t_list		*neighbours;
	char		state;
	int 		available;
}				t_spot;

t_spot		**ft_makeboard(t_obj input);
t_list		*ft_get_neighbours(int c, int r, t_obj input);
void		ft_get_info(t_obj *input);
t_list		*ft_get_available_move(t_spot **board, t_obj input);
t_list		*ft_get_physical_sqr(t_obj input);
void		ft_init_struct(t_obj *input);
void		ft_toplace(t_list *board, t_list *piece);
#endif
