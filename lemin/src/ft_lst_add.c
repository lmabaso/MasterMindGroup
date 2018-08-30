#include "../includes/lem-in.h"

int         ft_is_dup(t_string *node, char *to_find)
{
    while (node)
    {
        if (ft_strequ(node->str, to_find))
            return (1);
        node = node->next;
    }
    return (0);
}

void        ft_add_neigbour(t_node **head, char *room, char *neighbour)
{
    t_node *tmp;
    
    tmp = ft_find_room(*head, room);
    if (!ft_is_dup(tmp->data.neighbours, neighbour))
        ft_append_string(&tmp->data.neighbours, neighbour);
}

void        ft_add_coordinates(t_node **head, t_node *rooms, char *str)
{
    t_node *tmp;
    t_node *tmpr;
    

    tmp = ft_find_room(*head, str);
    tmpr = ft_find_room(rooms, str);
    tmp->data.pos.x = tmpr->data.pos.x;
    tmp->data.pos.y = tmpr->data.pos.y;
    tmpr = tmpr->next;
}