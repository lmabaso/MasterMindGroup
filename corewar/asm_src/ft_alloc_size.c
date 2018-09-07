#include "../includes/corewar.h"

int     ft_alloc_size(char *arg)
{
    char **str;
    int i;
    int size;

    size = 0;
    i = 0;
    str = ft_strsplit(arg, ',');
    while (str[i])
    {
        if (str[i][0] == 'r')
            size += 1;
        else if (str[i][0] == '%')
            size += 4;
        else
            size += 2;
        i++;
    }
    return (size);
}