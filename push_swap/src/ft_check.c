#include "../includes/push_swap.h"
#include "stdio.h"

int     ft_issorted(t_list **head)
{
    t_list *tmp;

    if (!*head || !(*head)->next)
        return (1);
    tmp = *head;

    while (tmp && tmp->next)
    {
        if (*(int *)tmp->content > *(int *)tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int      ft_isrsorted(t_list **head)
{
    t_list *tmp;

    if (!*head || !(*head)->next)
        return (1);
    tmp = *head;
    while (tmp && tmp->next)
    {
        if (*(int *)tmp->content < *(int *)tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int     ft_isdone(t_list **a, t_list **b)
{
    return (ft_issorted(a) && b == NULL) ? 1 : 0;
}