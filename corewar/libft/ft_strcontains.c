#include "libft.h"

int     ft_strcontains(char *str, char delim)
{
    while (*str)
    {
        if (*str == delim)
            return (1);
        str++;
    }
    return (0);
}
