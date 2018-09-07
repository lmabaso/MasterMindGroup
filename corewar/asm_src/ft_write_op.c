#include "../includes/corewar.h"

unsigned char *ft_sti(char *str)
{
    unsigned char   *code;
    unsigned char   encode;
    int             size;
    int             i;

    encode = ft_encode(str);
    size = ft_alloc_size(str);
    code = ft_memalloc((sizeof(unsigned char) * size) + 2);
    code[0] = 11;
    i = 1;
    code[i] = encode;
    while (i++ < size)
    {
        code[i] = 0;
    }
    return (code);
}