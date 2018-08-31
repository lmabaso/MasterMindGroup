#include "../includes/corewar.h"

int		ft_islabel(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		if (*str == ':')
			return (1);
		str++;
	}
	return (0);
}

void	ft_process_input(t_obj *c)
{
	char		**tmp;
    char        *hold;
	int			i;

	tmp = NULL;
    hold = NULL;
	if (ft_strlen(c->fixinput) != 0)
	{
		if (ft_islabel(c->fixinput))
		{
			tmp = ft_strsplit(c->fixinput, ' ');
			c->entry.label = ft_strdup(tmp[0]);
			c->entry.opcode = ft_strdup(tmp[1]);
			c->entry.data = ft_strdup(tmp[2]);
            if (ft_double_ptr_len((void **)tmp) > 2)
            {
                i = 2;
                while (tmp[i])
                {
                    hold = c->entry.data;
                    c->entry.data = ft_strjoin(c->entry.data , tmp[i]);
                    free(hold);
                    i++;
                } 
            }
			ft_append(&c->raw, c->entry);
			i = 0;
			while (tmp[i])
			{
				free(tmp[i]);
				i++;
			}
			free(tmp);
			tmp = NULL;
		}
		else
		{
			tmp = ft_strsplit(c->fixinput, ' ');
			c->entry.label = NULL;
			c->entry.opcode = ft_strdup(tmp[0]);
			c->entry.data = ft_strdup(tmp[1]);
            if (ft_double_ptr_len((void **)tmp) > 2)
            {
                i = 2;
                while (tmp[i])
                {
                    hold = c->entry.data;
                    c->entry.data = ft_strjoin(c->entry.data , tmp[i]);
                    free(hold);
                    i++;
                } 
            }
			ft_append(&c->raw, c->entry);
			i = 0;
			while (tmp[i])
			{
				free(tmp[i]);
				i++;
			}
			free(tmp);
			tmp = NULL;
		}
	}
}

void	ft_read_file(t_obj *c, int fdr)
{
	while (get_next_line(fdr, &c->line))
	{
		c->fixinput = ft_strfix(c->line);
		if (c->line[0] == '.')
			ft_init_header(c);
		else
			ft_process_input(c);
		free(c->line);
		free(c->fixinput);
	}
}