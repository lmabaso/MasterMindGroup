#include "get_next_line.h"

static ssize_t		readline(const int fd, char **line)
{
	char	*buff;
	ssize_t chars_read;
	char	*tmp;

	if (!(buff = ft_strnew(sizeof(char *) * BUFF_SIZE + 1)))
		return (-1);
	chars_read = read(fd, buff, BUFF_SIZE);
	if (chars_read > 0)
	{
		buff[chars_read] = '\0';
		ft_putendl("test-0 line============");
		ft_putendl(*line);
		ft_putendl("test-2 buff============");
		ft_putendl(buff);
		ft_putendl("");
		tmp = ft_strcat(*line, buff);
		if (!*line)
			return (-1);
		*line = ft_strdup(tmp);
	}
	if(buff)
	  free(buff);
	// ft_putendl("test0 line============");
	// ft_putendl(*line);
	// ft_putendl("test1 str============");
	// ft_putendl(tmp);
	// ft_putendl("test2 buff============");
	// ft_putendl(buff);
	// ft_putendl("1");
	return (chars_read);
}

int		lines(const int fd, char **str, char **newline)
{
	ssize_t lines_read;

	lines_read = readline(fd, *(&str));
	if (lines_read > 0)
		*newline = ft_strchr(*str, '\n');
	if (lines_read == 0)
	{
		if (ft_strlen(*str) == 0)
			return (0);
		*str = ft_strjoin(*str, "\n");
	}
	if (lines_read < 0)
		return (-1);
	return (1);
}

int		get_next_line(const int fd,char **line)
{
	static char	*str;
	char		*newline;

	if (((!str && !(str = ft_strnew(sizeof(char *) * BUFF_SIZE + 1)))
				|| (!line || fd < 0 || BUFF_SIZE < 0)))
		return (-1);
	while (!(newline = ft_strchr(str, '\n')))
	{
		if (lines(fd, &str, &newline) != 1)
			return (lines(fd, &str, &newline));
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(newline));
	str = ft_strdup(newline + 1);
	// ft_putendl("+!+!+!!!line+!+!+!+!!+!+");
	// ft_putendl(*line);
	return (1);
}
