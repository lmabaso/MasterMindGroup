#include "../includes/push_swap.h"

t_list      *ft_pop(t_list **head)
{
    t_list  *pop;

    pop = NULL;
    if (!*head)
        return (NULL);
    pop = *head;
    *head = (*head)->next;
    pop->next = NULL;
    return (pop);
}

void        ft_push_to(t_list **dest, t_list **src)
{
    ft_lstadd(dest, ft_pop(src));
}