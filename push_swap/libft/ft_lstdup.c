#include "libft.h"

t_list      *ft_lstdup(t_list *head)
{
    t_list *tmp;

    tmp = NULL;
    while (head)
    {
        ft_lstadd(&tmp, ft_lstnew(head->content, head->content_size));
        head = head->next;
    }
    return (tmp);
}