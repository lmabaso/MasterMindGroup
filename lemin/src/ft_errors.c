#include "../includes/lem-in.h"

int     ft_same_co(t_node *room)
{
    t_node *tmp;
    t_node *tmp1;

    tmp = room;
    while (tmp && tmp->next)
    {
        tmp1 = tmp;
        while (tmp1->next)
        {
            if ((tmp->data.pos.x == tmp1->next->data.pos.x) && (tmp->data.pos.y == tmp1->next->data.pos.y))
                return (1);
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    return (0);
}

int     ft_is_only_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isspace(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int     ft_dup(t_string *input)
{
    t_string *tmp;
    t_string *tmp1;

    tmp = input;
    while (tmp && tmp->next)
    {
        tmp1 = tmp;
        while (tmp1->next)
        {
            if (ft_strequ(tmp->str, tmp1->next->str))
                return (1);
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    return (0);
}