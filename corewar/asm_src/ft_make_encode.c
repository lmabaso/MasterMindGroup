#include "../includes/corewar.h"

unsigned char   ft_encode(char *arg)
{
    unsigned char encode;
    char **str;
    int i;

    i = 0;
    str = NULL;
    encode = 0;
    str = ft_strsplit(arg, SEPARATOR_CHAR);
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
            if (i == 3)
                encode += 1;
        }
        else if (str[i][0] == DIRECT_CHAR)
        {
            if (i == 0)
                encode += 128;
            if (i == 1)
                encode += 32;
            if (i == 2)
                encode += 8;
            if (i == 3)
                encode += 2;
        }
        else 
        {
            if (i == 0)
                encode += 192;
            if (i == 1)
                encode += 48;
            if (i == 2)
                encode += 12;
            if (i == 3)
                encode += 3;
        }
        
        i++;
    }
    return (encode);
}