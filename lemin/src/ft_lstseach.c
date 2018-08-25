#include "../includes/lem-in.h"

int ft_search_node(t_node *head, char *x)
{
    t_node* current;

    current = head;
    while (current != NULL)
    {
        if (ft_strequ(current->data.room_num, x))
            return (1);
        current = current->next;
    }
    return (0);
}

t_node *ft_find_room(t_node *head, char *room)
{
    t_node* current;

    current = head;
    while (current != NULL)
    {
        if (ft_strequ(current->data.room_num, room))
            return (current);
        current = current->next;
    }
    return (NULL);
}