#include "../includes/corewar.h"
#include <fcntl.h>

int     main(int ac, char **av)
{
    int fd;
    char *line;
    
    if (ac < 2)
    {
        ft_putendl("We'd like your input");
        return (0);
    }
    fd = 0;
    fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line))
    {
        ft_putendl(line);
        free(line);
    }
    return (1);
}