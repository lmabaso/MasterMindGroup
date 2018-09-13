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
        str[i] = ft_strtrim(str[i]);
        if (str[i][0] == 'r')
            size += 1;
        else if (str[i][0] == '%')
            size += 2;
        else
            size += 4;
        i++;
    }
    return (size);
}