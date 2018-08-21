#include "../includes/push_swap.h"
#include <stdio.h>
#include <fcntl.h>

void        ft_print(t_list **a, t_list **b, int fd)
{
    t_list *tmp1;
    t_list *tmp2;

    tmp1 = *a;
    tmp2 = *b;
    dprintf(fd, "A   B\n");
    while (tmp1)
    {
        if (tmp1 && tmp2)
            dprintf(fd, "%d   %d\n", *(int *)tmp1->content, *(int *)tmp2->content);
        if (tmp1 && !tmp2)
            dprintf(fd, "%d   \n", *(int *)tmp1->content);
        // if (!tmp1 && tmp2)
        //     printf("     %d\n", *(int *)tmp1->content);
        if (tmp1)
            tmp1 = tmp1->next;
        if (tmp2)
            tmp2 = tmp2->next;
    }
     dprintf(fd, "============\n");
}