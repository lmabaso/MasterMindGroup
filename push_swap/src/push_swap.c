#include "../includes/push_swap.h"
#include <fcntl.h>

void        ft_do_magic(t_list **a, t_list**b)
{
    char   *to_do;
    size_t     i;

    i = ft_lstlen(*a);
    while (1)
    {
        to_do = ft_make(a, b, i);
        ft_update(a, b, to_do);
        if (ft_strncmp(to_do, "ok", 2) == 0)
            break ;
    }
}

int     main(int ac, char **av)
{  
    t_list  *a;
    t_list  *b;

    init_check(ac, av, &a, &b);
    ft_do_magic(&a, &b);
    ft_lstfree(&a);
    ft_lstfree(&b);
}