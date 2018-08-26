#include "../includes/lem-in.h"

t_string *copy_string(t_string *L1)
{
     t_string *L2 = 0;
     t_string *preElem = 0;
     t_string *elem;

     while(L1 != 0)
     {
        if (!(elem = ft_memalloc(sizeof(t_string))))
            return (NULL);
        elem->str = ft_strdup(L1->str);
        elem->next = 0;
        if (L2 == 0)
        {
            L2 = elem;
            preElem = elem;
        }
        else
        {
            preElem->next = elem;
            preElem = elem;
		}
        L1 = L1->next;
    }
    return L2;
}

t_node      *ft_node_dup(t_node *L1)
{
    t_node *elem = NULL;

    elem = ft_memalloc(sizeof(t_node));
    if(elem == 0) {
        exit(1);
    }
    elem->data = L1->data;
    elem->data.f = L1->data.f;
    elem->data.g = L1->data.g;
    elem->data.neighbours = copy_string(L1->data.neighbours);
    elem->data.previous = NULL;
    elem->data.room_num = L1->data.room_num;
    elem->next = NULL;
    return (elem);
}

t_node      *copy(t_node *L1)
{
     t_node *L2 = NULL;
     t_node *preElem = NULL;
     t_node *elem = NULL;

     while(L1 != NULL) {
          elem = ft_memalloc(sizeof(t_node));
          if(elem == 0) {
               exit(1);
          }
          elem->data = L1->data;
          elem->data.f = L1->data.f;
          elem->data.g = L1->data.g;
          elem->data.neighbours = copy_string(L1->data.neighbours);
          elem->data.previous = NULL;
          elem->data.room_num = L1->data.room_num;
          elem->next = NULL;
          if (L2 == 0) {
                L2 = elem;
                preElem = elem;
          }
          else {
                preElem->next = elem;
                preElem = elem;
		  }
          L1 = L1->next;
    }
    return L2;
}

void deleteNode(t_node **head_ref, char *key)
{
    t_node* temp = *head_ref, *prev;
 
    if (temp != NULL && ft_strequ(temp->data.room_num, key))
    {
        *head_ref = temp->next;
        free(temp); 
        return;
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

void        ft_add_coordinates(t_node **head, t_list *rooms)
{
    t_node *tmp;
    t_room *tmpr;
    
    while (rooms)
    {
        tmpr = rooms->content;
        tmp = ft_find_room(*head, tmpr->room_num);
        tmp->data.pos.x = tmpr->pos.x;
        tmp->data.pos.y = tmpr->pos.y;
        rooms = rooms->next;
    }
}