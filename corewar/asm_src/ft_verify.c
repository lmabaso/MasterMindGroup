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

void	ft_check_input(int ac, char **ag)
{
	char *tmp;

	tmp = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage: ./asm [-a] <sourcefile.s>");
		ft_putendl("\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output");
		exit(0);
	}
	else
	{
		tmp = ft_strrchr(ag[1], '.');
		if (ft_strncmp(".s", tmp, 2))
		{
			ft_putendl("Invalid file input");
			tmp = NULL;
			exit(0);
		}
	}
	
}

void	ft_process_input(t_obj *c)
{
	char		**tmp;
	int			i;

	tmp = NULL;
	if (ft_strlen(c->fixinput) != 0)
	{
		if (ft_islabel(c->fixinput))
		{
			tmp = ft_strsplit(c->fixinput, ' ');
			c->entry.label = ft_strdup(tmp[0]);
			c->entry.opcode = ft_strdup(tmp[1]);
			c->entry.data = ft_strdup(tmp[2]);
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