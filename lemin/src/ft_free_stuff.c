#include "../includes/lem-in.h"

void    ft_node_str_free(t_string **head)
{
    t_string  *current;
    t_string  *next;

    current = *head;
    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
    *head = NULL;
}

void    ft_node_free2(t_node **head)
{
    t_node  *current;
    t_node  *next;

    current = *head;
    while (current != NULL)
    {
        next = current->next;
        free(current->data.room_num);
        free(current);
        current = next;
    }
    *head = NULL;
}

void    ft_free_map(t_node **map)
{
    t_node *tmp;

    tmp = *map;
    while (tmp)
    {
        ft_node_str_free(&tmp->data.neighbours);
        tmp = tmp->next;
    }
    ft_node_free2(map);
}

void        ft_delete_ant(t_colony **head_ref, char *key)
{
    t_colony  *temp;
    t_colony  *prev;

    temp = *head_ref;
    prev = NULL;
    if (temp != NULL && ft_strequ(temp->ant.room->str, key))
    {
        *head_ref = temp->next;
        free(temp->ant.ant_name);
        free(temp);
        return ;
    }
    while (temp != NULL && !ft_strequ(temp->ant.room->str, key))
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return ;
    prev->next = temp->next;
    free(temp->ant.ant_name);
    free(temp);
}

void    ft_remove_ants_at_end(t_colony **ants_in_maize, t_data *c)
{
    t_colony *tmp;

    tmp = *ants_in_maize;
    while (tmp)
    {
        if (ft_strequ(tmp->ant.room->str, c->end))
        {
            ft_delete_ant(ants_in_maize, c->end);
        }
        tmp = tmp->next;
    }
}