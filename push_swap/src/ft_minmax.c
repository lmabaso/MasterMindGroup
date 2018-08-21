#include "../includes/push_swap.h"

int     ft_min(t_list **head)
{
    t_list  *tmp;
    int     min;

    tmp = *head;
    min = *(int *)tmp->content;
    while (tmp)
    {
        if (min > *(int *)tmp->content)
            min = *(int *)tmp->content;
        tmp = tmp->next;
    }
    return (min);
}

int     ft_max(t_list **head)
{
    t_list  *tmp;
    int     max;

    tmp = *head;
    max = *(int *)tmp->content;
    while (tmp)
    {
        if (max < *(int *)tmp->content)
            max = *(int *)tmp->content;
        tmp = tmp->next;
    }
    return (max);
}

int     ft_first(t_list **head)
{
    return (*(int *)(*head)->content);
}

int     ft_second(t_list **head)
{
    return (*(int *)(*head)->next->content);
}

int     ft_last(t_list **head)
{
    t_list *tmp;

    tmp = *head;
    while (tmp && tmp->next)
    {
        tmp = tmp->next;
    }
    return (*(int *)tmp->content);
}

int     ft_pos(t_list **head, int num)
{
    int		index;
	t_list *tmp;

	tmp = *head;
	index = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == num)
			break ;
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int     ft_at_index(t_list **head, int index)
{
    t_list *tmp;

    tmp = *head;
    while (index)
    {
        tmp = tmp->next;
        index--;
    }
    return (*(int *)tmp->content);
}