#include "../includes/corewar.h"

void	ft_init_header(t_obj *c)
{
	char		**tmp;
	int i;

	if (ft_strequ(c->line, NAME_CMD_STRING))
	{
		tmp = ft_strsplit(c->fixinput, ' ');
		ft_strcat(c->info->prog_name, tmp[1]);
		i = 0;
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
	else if (ft_strequ(c->line, COMMENT_CMD_STRING))
	{
		tmp = ft_strsplit(c->fixinput, ' ');
		ft_strcat(c->info->comment , tmp[1]);
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

char	*ft_strfix(char *str)
{
	char	*fix;
	size_t	i;

	i = 0;
	if (!(fix = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			fix[i] = ' ';
		else
			fix[i] = str[i];
		i++;
	}
	return (fix);
}

void	ft_init(t_obj *c)
{
	c->info = ft_memalloc(sizeof(header_t));
	c->raw = NULL;
}