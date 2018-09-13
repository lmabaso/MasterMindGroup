#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "op.h"

typedef struct      s_lables
{
    char            *lable;
    unsigned int    addr;
    struct s_lables *next;
}                   t_lables;

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
    t_lables        *lables;
    t_node		    *raw;
    t_data          entry;
}                   t_obj;

void                ft_init(t_obj *c);
char                *ft_strfix(char *str);
void	            ft_init_header(t_obj *c);

void                ft_lfree(t_node **head);
void	            ft_to_free(t_obj *c);

void                ft_check_input(int ac, char **ag);

void		        ft_append(t_node** head, t_data new_data);

void                ft_process_input(t_obj *c);
void	            ft_read_file(t_obj *c, int fdr);

unsigned char       ft_encode(char *arg);
int                 ft_alloc_size(char *arg);

void                ft_puthex(int hex, int fd);
void                ft_write_header(t_obj *c, int fd);

t_output            ft_sti(char *str, t_obj *c, int make);
t_output            ft_and(char *str, t_obj *c, int make);
t_output            ft_live(char *str, t_obj *c, int make);
t_output            ft_zjmp(char *str, t_obj *c, int make);
#endif