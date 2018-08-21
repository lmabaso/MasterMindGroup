#include "../includes/push_swap.h"

void    ft_correct(int *ac, char ***av)
{
    if (*ac == 1 && ft_strcontains(*av[0], ' '))
    {
        *av = ft_strsplit(*av[0], ' ');
        *ac = ft_double_ptr_len((void **)*av);
    }
}

int     ft_isvalid(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 0)
        return (0);
    while (i < ac)
    {
        if (!ft_isnumber(av[i]))
            return (0);
        i++;
    }
    return (1);
}

void    ft_check_for_errors(int ac, char **av)
{
    if (ft_strequ(*av, "") || !ft_isvalid(ac, av))
    {
        ft_putendl("Error");
        exit(1);
    }
}

int     ft_is_in_stack(t_list *stack, int num)
{
    int *tmp;

    if (!stack)
        return (0);
    tmp = NULL;
    while (stack)
    {
        tmp = stack->content;
        if (*tmp == num)
            return(1);
        stack = stack->next;
    }
    return (0);
}