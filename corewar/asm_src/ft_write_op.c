#include "../includes/corewar.h"

unsigned char       *ft_indirect(char *str)
{
    unsigned char   *tmp;
    int i;

    i = 0;
    tmp = ft_memalloc(IND_CODE + 1);
    if (ft_isnumber(str))
    {
        i = ft_atoi(str);
        ft_putnbr(i);
        tmp[0] = i / 1024;
        tmp[1] = i / 512;
        tmp[2] = i / 255;
        tmp[3] = i % 255;
    }
    return (tmp);
}

unsigned char       *ft_direct(char *str)
{
    unsigned char   *tmp;
    int i;

    i = 0;
    tmp = ft_memalloc(DIR_CODE);
    if (ft_isnumber(&str[1]))
    {
        i = ft_atoi(&str[1]);
        tmp[0] = i / 255;
        tmp[1] = i % 255;
    }
    return (tmp);
}

unsigned char       *ft_manage_arg(int size, char *str)
{
    unsigned char   *tmp;
    unsigned char   *t;
    char            **s;
    int             i;
    int             j;
    int             a;

    s = ft_strsplit(str, ',');
    a = 0;
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
            a = 0;
            t = ft_direct(s[i]);
            while (a < 2)
            {
                tmp[j] = t[a];
                a++;
                j++;
            }
        }
        else
        {
            t = ft_indirect(s[i]);
            a = 0;
            while (a < 4)
            {
                tmp[j] = t[a];
                a++;
                j++;
            }
        }
        i++;
    }
    return (tmp);
}

t_output            ft_sti(char *str)
{
    t_output        code;
    unsigned char   encode;
    unsigned char   *tmp;
    int             size;
    int             i;
    int             j;

    encode = ft_encode(str);
    size = ft_alloc_size(str);
    ft_putnbr(size);
    code.bytes = ft_memalloc(2 + size);
    code.bytes[0] = 11;
    code.bytes[1] = encode;
    tmp = ft_manage_arg(size, str);
    i = 2;
    j = 0;
    while (j < size)
    {
        code.bytes[i] = tmp[j];
        i++;
        j++;
    }
    code.size = size + 2;
    return (code);
}