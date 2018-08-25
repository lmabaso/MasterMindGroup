#include "../includes/lem-in.h"

t_string        *ft_astar(t_data *c, t_node *map)
{
    t_string    *path_to_finish;
    t_node      *openSet;
    // t_node      *closedSet;
    // char        *current;
    // char        *tmp;
    // t_room      *neighbour;
    // double      tmpG;
    t_node      *winner;
    t_node      *ptr;

    openSet = NULL;
    path_to_finish = NULL;
    ft_append_data(&openSet, ft_find_room(map, c->start)->data);
    while (ft_lst_str_len(openSet) > 0)
    {
        winner = NULL;
        ptr = openSet;
        while (ptr)
        {

            ptr = ptr->next;
        }
    }
    return (path_to_finish);
}