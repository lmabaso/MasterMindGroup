#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

typedef struct      s_string
{
    char            *str;
    struct s_string *next;
}                   t_string;

typedef struct      s_co
{
    int             x;
    int             y;
}                   t_co;

typedef struct      s_room
{
    char            *room_num;
    t_co            pos;
    double          f;
    double          g;
    double          h;
    t_string        *neighbours;
    struct s_room   *previous;
}                   t_room;

typedef struct      s_node
{
    size_t          index;
    t_room          data;
    struct s_node   *next;
}                   t_node;

typedef struct      s_data
{
    int             nb_ants;
    char            *start;
    char            *end;
    t_node          *cells;
    t_string        *tubs;
}                   t_data;

void                ft_add_neigbour(t_node **head, char *room, char *neighbour);
t_node              *ft_find_room(t_node *head, char *room);
void		        ft_append(t_node** head, char *new_data);
void                ft_append_data(t_node **head, t_room new_data);
void		        ft_append_string(t_string** head, char *new_data);
int                 ft_search_node(t_node* head, char *x);
void                ft_show_input(t_data *c, t_node *map);

size_t              ft_lst_node_len(t_node *head);
size_t              ft_lst_str_len(t_string *head);
void                deleteNode(t_node **head_ref, char *key);

t_string            *ft_astar(t_data *c, t_node *map);
t_node              *ft_node_dup(t_node *L1);
void                ft_get_room(t_node **head, char *room);
void                ft_add_coordinates(t_node **head, t_node *rooms);

double              ft_get_distance(t_co a, t_co b);
#endif