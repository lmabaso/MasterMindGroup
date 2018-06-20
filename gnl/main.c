#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int c, char **av)
{
	int fd;
	char *line;

	if (c < 2)
	{
		ft_putendl("We'd realy like your input");
		return (0);
	}
	fd = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	//get_next_line(fd, &line);
	//ft_putendl(line);
	return (0);
}
