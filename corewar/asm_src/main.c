#include "../includes/corewar.h"
#include <fcntl.h>
#include <stdio.h>

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

int		main(int c, char **av)
{
	header_t	*info;
	int			fdr;
	char		*line;
	t_list		*raw_data;
	t_data		entry;
	int			index;
	t_data		*tmp;
	char		*tmp0;
	char		**tmp1;
	
	tmp1 = NULL;
	raw_data = NULL;
	info = ft_memalloc(sizeof(header_t));
	if (c < 2)
	{
		ft_putendl("We'd realy like your input");
		return (0);
	}
	fdr = 0;
	fdr = open(av[1], O_RDONLY);
	while (get_next_line(fdr, &line))
	{
		index = 0;
		if (line[0] == '.')
		{
			if (ft_strncmp(line, ".name", 5) == 0)
			{
				index = 5;
				while (line[index] == ' ')
					index++;
				ft_strcat(info->prog_name, &line[index]);
			}
			if (ft_strncmp(line, ".comment", 8) == 0)
			{
				index = 8;
				while (line[index] == ' ')
					index++;
				ft_strcat(info->comment , &line[index]);
			}
		}
		else
		{
			index = 0;
			if (ft_islabel(line))
			{
				tmp0 = ft_strfix(line);
				tmp1 = ft_strsplit(tmp0, ' ');
				entry.label = tmp1[0];
				entry.opcode = tmp1[1];
				entry.data = tmp1[2];
				ft_lstadd(&raw_data, ft_lstnew(&entry, sizeof(t_data)));
			}
			// else if (index == 0)
			// {
			// 	entry.label = NULL;
			// 	ft_lstadd(&raw_data, ft_lstnew(&entry, sizeof(t_data)));
			// }
				
			
		}
		// ft_putendl(line);
		free(line);
	}
	while (raw_data)
	{
		tmp = raw_data->content;
		// ft_putstr(tmp->label);
		// ft_putstr(" ");
		// ft_putstr(tmp->opcode);
		ft_putstr("\n");
		ft_putstr(tmp->data);
		raw_data = raw_data->next;
	}
	// fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	// ft_putuchar_fd(0, fdw);
	// ft_putuchar_fd(234, fdw);
	// ft_putuchar_fd(131, fdw);
	// ft_putuchar_fd(243, fdw);

	
	// ft_putstr_fd(ft_strrchr(line, ' ') + 2, fdw);
	return (0);
}
