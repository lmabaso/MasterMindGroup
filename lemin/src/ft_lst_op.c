#include "../includes/lem-in.h"

size_t         ft_lst_node_len(t_node *head)
{
    size_t i;

    i = 0;
    while (head)
    {
        i++;
        head = head->next;
    }
    return (i);
}

size_t         ft_lst_str_len(t_string *head)
{
    size_t i;

    i = 0;
    while (head)
    {
        i++;
        head = head->next;
    }
    return (i);
}