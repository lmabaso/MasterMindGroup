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


#endif