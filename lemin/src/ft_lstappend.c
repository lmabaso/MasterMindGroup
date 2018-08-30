#include "../includes/lem-in.h"

void        ft_reverse(t_string **head_ref)
{
    t_string  *prev   = NULL;
    t_string  *current = *head_ref;
    t_string  *next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void deleteStr(t_string **head_ref, char *key)
{
    t_string  *temp;
    t_string  *prev;

    temp = *head_ref;
    prev = NULL;
    if (temp != NULL && ft_strequ(temp->str, key))
    {
        *head_ref = temp->next;
        free(temp); 
        return ;
    }

    while (temp != NULL && !ft_strequ(temp->str, key))
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return ;
    prev->next = temp->next;
    free(temp);
}

void deleteNode(t_node **head_ref, char *key)
{
    t_node  *temp;
    t_node  *prev;

    temp = *head_ref;
    prev = NULL;
    if (temp != NULL && ft_strequ(temp->data.room_num, key))
    {
        *head_ref = temp->next;
        free(temp); 
        return ;
    }

    while (temp != NULL && !ft_strequ(temp->data.room_num, key))
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return ;
    prev->next = temp->next;
    free(temp);
}

void		ft_append_string(t_string** head, char *new_data)
{
    t_string	*new_node;
    t_string	*last;

	new_node = ft_memalloc(sizeof(t_string));
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