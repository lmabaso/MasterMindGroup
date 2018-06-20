#include "get_next_line.h"

static ssize_t		readline(const int fd, char **line)
{
	char	*buff;
	ssize_t chars_read;
	char	*tmp;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	chars_read = read(fd, buff, BUFF_SIZE);
	if (chars_read > 0)
	{
		buff[chars_read] = '\0';
	ft_putendl("test-0 line============");
	ft_putendl(*line);
	ft_putendl("test-2 buff============");
	ft_putendl(buff);
		tmp = ft_strjoin(*line, buff);
		free(*line);
		ft_putendl(*line);
		*line = tmp;
	}
	//	free(buff);
	ft_putendl("test0 line============");
	ft_putendl(*line);
	ft_putendl("test1 str============");
	ft_putendl(tmp);
	ft_putendl("test2 buff============");
	ft_putendl(buff);
	return (chars_read);
}

int		get_next_line(const int fd,char **line)
{
	static char	*str;
	ssize_t		lines_read;
	char		*newline;

	if (!(str = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	newline = ft_strchr(str, '\n');
	while (newline == NULL)
	{
		lines_read = readline(fd, &str);
		if (lines_read > 0)
			newline = ft_strchr(str, '\n');
		if (lines_read == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (lines_read < 0)
			return (-1);
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(newline));
	str = ft_strdup(newline + 1);
	//ft_putendl("+!+!+!!!line+!+!+!+!!+!+");
	//ft_putendl(*line);
	return (1);
}
