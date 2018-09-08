#include "../includes/corewar.h"

void	ft_init_header(t_obj *c)
{
	char		**tmp;
	int i;
	char		*tm;

	if (ft_strstr(c->line, NAME_CMD_STRING))
	{
		
		tmp = ft_strsplit(c->fixinput, ' ');
		tm = ft_strsub(tmp[1], 1, ft_strlen(tmp[1]) - 2);
		ft_strcat(c->info->prog_name, tm);
		i = 0;
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
		free(tm);
		tm = NULL;
	}
	else if (ft_strstr(c->line, COMMENT_CMD_STRING))
	{
		tmp = ft_strsplit(c->fixinput, ' ');
		tm = ft_strsub(ft_strchr(c->fixinput, '"') + 1, 0, ft_strlen(ft_strchr(c->fixinput, '"')) - 2);
		ft_strcat(c->info->comment , tm);
		i = 0;
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
		free(tm);
		tm = NULL;
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