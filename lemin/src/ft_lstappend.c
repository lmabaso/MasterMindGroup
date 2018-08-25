#include "../includes/lem-in.h"

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

void		ft_append_string(t_string** head, char *new_data)
{
    t_string	*new_node;
    t_string	*last;

	new_node = ft_memalloc(sizeof(t_node));
	last = *head;
    new_node->str = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return ;
}

// void		ft_append_int(t_int **head, int new_data)
// {
//     t_int	*new_node;
//     t_int	*last;

// 	new_node = ft_memalloc(sizeof(t_node));
// 	last = *head;
//     new_node->value = new_data;
//     new_node->next = NULL;
//     if (*head == NULL)
//     {
//         *head = new_node;
//         return ;
//     }
//     while (last->next != NULL)
//         last = last->next;
//     last->next = new_node;
//     return ;
// }

void                ft_append_data(t_node **head, t_room new_data)
{
    t_node	*new_node;
    t_node	*last;

	new_node = ft_memalloc(sizeof(t_node));
	last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->index = 0;
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    new_node->index = last->index + 1;
    last->next = new_node;
    return ;
}


void		ft_append(t_node** head, char *new_data)
{
    t_node	*new_node;
    t_node	*last;
    t_room  data;

	new_node = ft_memalloc(sizeof(t_node));
	last = *head;
    data.room_num = new_data;
    data.neighbours = NULL;
    data.previous = NULL;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->index = 0;
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    new_node->index = last->index + 1;
    last->next = new_node;
    return ;
}

void        ft_add_neigbour(t_node **head, char *room, char *neighbour)
{
    t_node *tmp;
    
    tmp = ft_find_room(*head, room);
    ft_append_string(&tmp->data.neighbours, neighbour);
}