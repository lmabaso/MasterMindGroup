#include "../includes/corewar.h"

unsigned char   ft_encode(char *arg)
{
    unsigned char encode;
    char **str;
    int i;

    i = 0;
    str = NULL;
    encode = 0;
    str = ft_strsplit(arg, ',');
    while (str[i])
    {
        if (str[i][0] == 'r')
        {
            if (i == 0)
                encode += 64;
            if (i == 1)
                encode += 16;
            if (i == 2)
                encode += 4;
        }
        else if (str[i][0] == '%')
        {
            if (i == 0)
                encode += 128;
            if (i == 1)
                encode += 32;
            if (i == 2)
                encode += 8;
        }
        else
        {
            if (i == 0)
            {
                encode += 64;
                encode += 128;
            }
            if (i == 1)
            {
                encode += 32;
                encode += 16;
            }
            if (i == 2)
            {
                encode += 4;
                encode += 8;
            }
        }
        i++;
    }
    return (encode);
}