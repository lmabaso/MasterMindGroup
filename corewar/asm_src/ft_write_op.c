#include "../includes/corewar.h"

unsigned char       *ft_direct(char *str)
{
    unsigned char   *tmp;
}

unsigned char       *ft_manage_arg(int size, char *str)
{
    unsigned char   *tmp;
    char            **s;
    int             i;
    int             j;

    s = ft_strsplit(str, ',');
    i = 0;
    j = 0;
    tmp = ft_memalloc(size);
    while (s[i])
    {
        if (s[i][0] == 'r')
        {
            tmp[j] = ft_atoi(&s[i][1]);
            j++;
        }
        else if (s[i][0] == DIRECT_CHAR)
        {

            j += 2;
        }
        i++;
    }
    return (tmp);
}

unsigned char *ft_sti(char *str)
{
    unsigned char   *code;
    unsigned char   encode;
    int             size;
    int             i;

    encode = ft_encode(str);
    size = ft_alloc_size(str);
    ft_putnbr(size);
    code = ft_memalloc((sizeof(unsigned char) * size) + 2);
    code[0] = 11;
    i = 1;
    code[i] = encode;
    while (i++ < size + 2)
    {
        code[i] = 0;
    }
    return (code);
}