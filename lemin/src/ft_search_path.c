#include "../includes/lem-in.h"

t_node          *ft_as_lowest_f(t_node *head)
{
    t_node      *tmp;
    t_node      *winner;

    tmp = head;
    winner = ft_memalloc(sizeof(t_node));
    winner->data = head->data;
    while (tmp)
    {
        if (winner->data.f > tmp->data.f)
        {
            winner->data = tmp->data;
            // winner->data.previous = tmp->data.previous;
        }
            
        tmp = tmp->next;
    }
    return (winner);
}

void    ft_node_free(t_node **head)
{
    t_node  *current;
    t_node  *next;

    current = *head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

#include <stdio.h>

t_string        *ft_astar(t_data *c, t_node *map)
{
    t_string    *path_to_finish;
    t_node      *openSet;
    t_node      *closedSet;
    t_node      *current;
    t_node      *tmp;
    t_room      *neighbour;
    double      tmpG;
    t_node      *winner;
    t_room      element;
    t_string    *tmpNei;

    openSet = NULL;
    closedSet = NULL;
    path_to_finish = NULL;
    winner = NULL;
    
    ft_append_data(&openSet, ft_find_room(map, c->start)->data);
    while (ft_lst_node_len(openSet) > 0)
    {
        winner = ft_as_lowest_f(openSet);
        current = winner;
        if (ft_strequ(current->data.room_num, c->end))
        {
            tmp = current;
            winner = tmp;
            ft_append_string(&path_to_finish, tmp->data.room_num);
            while (tmp->data.previous != NULL)
            {
                ft_append_string(&path_to_finish, tmp->data.previous->room_num);
                tmp->data = *tmp->data.previous;
            }
            ft_node_free(&winner);
            break ;
        }
        deleteNode(&openSet, current->data.room_num);
        ft_append_data(&closedSet, ft_find_room(map, current->data.room_num)->data);
        element = ft_find_room(map, current->data.room_num)->data;
        tmpNei = element.neighbours;
        while (tmpNei)
        {
            neighbour = &ft_find_room(map, tmpNei->str)->data;
            neighbour->previous = &current->data;

            if (!ft_search_node(closedSet, neighbour->room_num))
            {
                tmpG = current->data.g + 1;
                if (ft_search_node(openSet, neighbour->room_num))
                {
                    if (tmpG < neighbour->g)
                        neighbour->g = tmpG;
                }
                else
                    neighbour->g = tmpG;
                neighbour->h = ft_get_distance(neighbour->pos, ft_find_room(map, c->end)->data.pos);
                neighbour->f = neighbour->g + neighbour->h;
                ft_append_data(&openSet, ft_find_room(map, neighbour->room_num)->data);
            }
            tmpNei = tmpNei->next;

        }
    }
    ft_node_free(&closedSet);
    ft_node_free(&openSet);
    ft_reverse(&path_to_finish);
    return (path_to_finish);
}