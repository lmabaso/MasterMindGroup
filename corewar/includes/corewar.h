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
#endif