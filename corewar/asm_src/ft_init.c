#include "../includes/corewar.h"

// fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	// ft_putuchar_fd(0, fdw);
	// ft_putuchar_fd(234, fdw);
	// ft_putuchar_fd(131, fdw);
	// ft_putuchar_fd(243, fdw);

	
	// ft_putstr_fd(ft_strrchr(line, ' ') + 2, fdw);
void	ft_init_header(t_obj *c)
{
	char		**tmp;
	int i;

	if (ft_strncmp(c->line, ".name", 5) == 0)
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
	else if (ft_strncmp(c->line, ".comment", 8) == 0)
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