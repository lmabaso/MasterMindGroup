#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct	s_moves
{
	int			elem;
	int			a_moves;
	int			b_moves;
	char		*a_rot;
	char		*b_rot;
	char		*common_rot;
	int			common_moves;
	int			total;
}				t_moves;

int         ft_is_in_stack(t_list *stack, int num);
void        ft_check_for_errors(int ac, char **av);
int         ft_isvalid(int ac, char **av);
void        ft_correct(int *ac, char ***av);
t_list      *ft_fresh_stack(int ac, char **av);

void        ft_rotate_up(t_list **head);
void        ft_rotate_dwn(t_list **head);
void        ft_rotate_up_rr(t_list **head_a, t_list **head_b);
void		ft_rotate_dwn_rr(t_list **head_a, t_list **head_b);

void        ft_swap(t_list **head);
void        ft_swap_ss(t_list **head_a, t_list **head_b);

void        ft_push_to(t_list **dest, t_list **src);

int         ft_issorted(t_list **head);
int         ft_isrsorted(t_list **head);
int     	ft_isdone(t_list **a, t_list **b);

int         ft_min(t_list **head);
int         ft_max(t_list **head);
int         ft_first(t_list **head);
int         ft_second(t_list **head);
int         ft_last(t_list **head);
int         ft_pos(t_list **head, int num);
int         ft_at_index(t_list **head, int index);

char        *ft_make(t_list **a, t_list **b, size_t i);
void        ft_print(t_list **a, t_list **b, int fd);

char        *ft_sort(t_list **a, t_list **b);
char        *ft_sort10(t_list **a, t_list **b);

int         ft_to_push(t_list **a, t_list **b);


int				pos_2b(t_list **b, int num, int index);
int				get_min_moves(int num, t_list **a, t_list **b);
int				direction(int num, t_list **a, t_list **b);
int				get_to_be_pushed(t_list **a, t_list **b);

void            ft_update(t_list **a, t_list**b, char *cmd);
void    		init_check(int ac, char **av, t_list **a, t_list **b);
#endif