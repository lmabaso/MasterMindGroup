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
        tmp[0] = i / 1024;
        tmp[1] = i / 512;
        tmp[2] = i / 255;
        tmp[3] = i % 255;
    }
    if (ft_isnumber(&str[1]))
    {
        i = ft_atoi(&str[1]);
        tmp[0] = i / 1024;
        tmp[1] = i / 512;
        tmp[2] = i / 255;
        tmp[3] = i % 255;
    }
    
    return (tmp);
}

t_lables            *find_lable(t_lables *head, char *str)
{
    t_lables        *tmp;

    tmp = head;
    while (tmp)
    {
        if (ft_strncmp(tmp->lable, str, ft_strlen(tmp->lable) - 1) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

unsigned char       *ft_direct(char *str, t_obj *c, int make)
{
    unsigned char   *tmp;
    int i;
    t_lables *t;

    i = 0;
    tmp = ft_memalloc(T_DIR);
    if (ft_isnumber(&str[1]))
    {
        i = ft_atoi(&str[1]);
        tmp[0] = i / 255;
        tmp[1] = i % 255;
    }
    else if (str[1] == LABEL_CHAR)
    {
        if (make == 1)
        {
            t = find_lable(c->lables, &str[2]);
            i = t->addr;
            tmp[0] = i / 255;
            tmp[1] = i % 255;
        }
    }
    return (tmp);
}

unsigned char       *ft_manage_arg_e(int size, char *str, t_obj *c, int make)
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
        s[i] = ft_strtrim(s[i]);
        if (s[i][0] == 'r')
        {
            tmp[j] = ft_atoi(&s[i][1]);
            j++;
        }
        else if (s[i][0] == DIRECT_CHAR)
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
        else
        {
            a = 0;
            t = ft_direct(s[i], c, make);
            while (a < 2)
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

unsigned char       *ft_manage_arg(int size, char *str, t_obj *c, int make)
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
        s[i] = ft_strtrim(s[i]);
        if (s[i][0] == 'r')
        {
            tmp[j] = ft_atoi(&s[i][1]);
            j++;
        }
        else if (s[i][0] == DIRECT_CHAR)
        {
            a = 0;
            t = ft_direct(s[i], c, make);
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

t_output            ft_sti(char *str, t_obj *c, int make)
{
    t_output        code;
    unsigned char   encode;
    unsigned char   *tmp;
    int             size;
    int             i;
    int             j;

    encode = ft_encode(str);
    size = ft_alloc_size(str) + 2;
    code.bytes = ft_memalloc(size);
    code.bytes[0] = 11;
    code.bytes[1] = encode;
    tmp = ft_manage_arg(size, str, c, make);
    i = 2;
    j = 0;
    while (j < size)
    {
        code.bytes[i] = tmp[j];
        i++;
        j++;
    }
    code.size = size;
    return (code);
}

t_output            ft_and(char *str, t_obj *c, int make)
{
    t_output        code;
    unsigned char   encode;
    unsigned char   *tmp;
    int             size;
    int             i;
    int             j;

    encode = ft_encode(str);
    size = 8;
    code.bytes = ft_memalloc(size);
    code.bytes[0] = 6;
    code.bytes[1] = encode;
    tmp = ft_manage_arg_e(size, str, c, make);
    i = 2;
    j = 0;
    while (j < size)
    {
        code.bytes[i] = tmp[j];
        i++;
        j++;
    }
    code.size = size;
    return (code);
}

t_output            ft_live(char *str, t_obj *c, int make)
{
    t_output        code;
    int             size;
    int             i;

    (void)c;
    (void)make;
    size = 5;
    code.bytes = ft_memalloc(size);
    code.bytes[0] = 1;
    i = ft_atoi(&str[1]);
    code.bytes[1] = i / 1024;
    code.bytes[2] = i / 512;
    code.bytes[3] = i / 255;
    code.bytes[4] = i % 255;
    code.size = size;
    return (code);
}

int binAddition(int a,int b) 
{
    int c;

    while (b != 0)
    {
        c = (a & b) << 1;
        a = a ^ b;
        b = c;
    }
    return a; 
}

int binSubtracton(int a, int b) 
{
    int carry;

    b = binAddition(~b, 1);
    while (b != 0)
    { 
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int       ft_d(char *str, t_obj *c, int make)
{
    int i;
    t_lables *t;

    i = 0;
    if (ft_isnumber(&str[1]))
        i = ft_atoi(&str[1]);
    else if (str[1] == LABEL_CHAR)
    {
        if (make == 1)
        {
            t = find_lable(c->lables, &str[2]);
            i = t->addr;
        }
    }
    return (i);
}

t_output            ft_zjmp(char *str, t_obj *c, int make, int pos)
{
    t_output        code;
    unsigned char   *tmp;
    int             size;
    int             a;

    
    (void)pos;
    size = ft_alloc_size(str) + 1;
    code.bytes = ft_memalloc(size);
    code.bytes[0] = 9;
    a = ft_d(str, c, make);
    a = 65536 + (a - pos);
    tmp = ft_direct(str, c, make);
    code.bytes[1] = a / 256;
    code.bytes[2] = a % 256;
    code.size = size;
    return (code);
}