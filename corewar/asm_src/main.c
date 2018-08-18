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

int		main(int c, char **av)
{
	header_t	*info;
	int			fdr;
	char		*line;
	t_list		*raw_data;
	t_data		entry;
	int			index;
	t_data		*tmp;
	
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
				index = ft_strlen(line) - ft_strlen(ft_strchr(line, ':'));
				entry.label = ft_strsub(line, 0, index);
				index++;
				while (ft_isspace(line[index]))
					index++;
				// line += index;
				// entry.opcode = ft_strsub(line, 0, ft_strlen(line));
				ft_lstadd(&raw_data, ft_lstnew(&entry, sizeof(t_data)));
			}
			// else if (index == 0)
			// {
			// 	entry.label = NULL;
			// 	ft_lstadd(&raw_data, ft_lstnew(&entry, sizeof(t_data)));
			// }
				
			
		}
		// ft_putendl(line);
		// free(line);
	}
	while (raw_data)
	{
		tmp = raw_data->content;
		ft_putendl(tmp->label);
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
