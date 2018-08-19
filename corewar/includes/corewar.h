#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "op.h"

typedef struct      s_output
{
    unsigned char   *bytes;
    int             size;
}                   t_output;

typedef struct      s_data
{
    char            *label;
    char            *opcode;
    char            *data;
}                   t_data;

typedef struct      s_node
{
    t_data          entry;
    struct s_node   *next;
}                   t_node;

typedef struct      s_obj
{
    char            *line;
    char		    *fixinput;
    header_t        *info;
    t_node		    *raw;
    t_data          entry;
}                   t_obj;

void                ft_init(t_obj *c);
char                *ft_strfix(char *str);
void	            ft_init_header(t_obj *c);

void                ft_lfree(t_node **head);
void	            ft_to_free(t_obj *c);
#endif