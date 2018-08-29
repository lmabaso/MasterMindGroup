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

void    ft_process_input(t_string *input, t_data *c)
{
    t_string *tmp;
    t_room  tmpr;
    char     **s;
    int     i;
    int     start;
    int     end;

    start = 0;
    end = 0;
    tmp = input;
    ft_isnumber(tmp->str) ?
    (c->nb_ants = ft_atoi(tmp->str) , tmp = tmp->next) :
    (ft_node_str_free(&input), free(c), ft_putendl("error"), exit(1));
    while (tmp)
    {
        if (!ft_strequ(tmp->str, "##start") && !ft_strequ(tmp->str, "##end"))
        {
            s = ft_strsplit(tmp->str, ' ');
            if (ft_double_ptr_len((void **)s) == 3)
            {
                (start == 1) ? c->start = ft_strdup(s[0]) : c->start; 
                (end == 1) ? c->end = ft_strdup(s[0]) : c->end;
                tmpr.room_num = ft_strdup(s[0]);
                tmpr.pos.x = ft_atoi(s[1]);
                tmpr.pos.y = ft_atoi(s[2]);
                ft_append_data(&c->cells, tmpr);
                // ft_lstadd(&c->cells, ft_lstnew(&tmpr, sizeof(t_room)));
                start = 0;
                end = 0;
            }
            i = 0;
            while (s[i])
            {
                free(s[i]),i++;
            }
            free(s);
            s = NULL;
        }
        start = (ft_strequ(tmp->str, "##start") ? 1 : 0);
        end = (ft_strequ(tmp->str, "##end") ? 1 : 0);
        if (ft_strchr(tmp->str, '-'))
            break ;
        tmp = tmp->next;
    }
    while (tmp)
    {
        if (ft_strchr(tmp->str, '-'))
            ft_append_string(&c->tubs, ft_strdup(tmp->str));
        else
            break ;
        tmp = tmp->next;
    }
}

void    ft_creat_links(t_node **map, t_data *c)
{
    t_string *tmp;
    char     **s;
    int     i;

    tmp = c->tubs;
    while (tmp)
    {
        s = ft_strsplit(tmp->str, '-');
        if (ft_double_ptr_len((void **)s) == 2)
        {
            (ft_search_node(*map, s[0])) ?
            ft_add_neigbour(map, s[0], ft_strdup(s[1])) :
            (ft_append(map, ft_strdup(s[0])), ft_add_neigbour(map, s[0], ft_strdup(s[1])));
            (ft_search_node(*map, s[1])) ?
            ft_add_neigbour(map, s[1], ft_strdup(s[0])) :
            (ft_append(map, ft_strdup(s[1])), ft_add_neigbour(map, s[1], ft_strdup(s[0])));
        }
        i = 0;
        while (s[i])
        {
            free(s[i]);
            i++;
        }
        free(s);
        s = NULL;
        tmp = tmp->next;
    }
}

void		ft_trans_ant(t_colony** head, t_colony *new_data)
{
    t_colony	*new_node;
    t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
    new_node = new_data;
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

void		ft_append_ant(t_colony** head, char *new_data)
{
    t_colony	*new_node;
    t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
    new_node->ant.ant_name = new_data;
    new_node->ant.room = NULL;
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

t_colony    *ft_get_ants(t_data *c)
{
    t_colony    *ant_farm;
    int i;

    i = 1;
    ant_farm = NULL;
    while (i <= c->nb_ants)
    {
        ft_append_ant(&ant_farm, ft_strjoin("L", ft_itoa(i)));
        i++;
    }
    return (ant_farm);
}

void    ft_get_moving(t_ant mr_ant)
{
    while (mr_ant.room)
    {
        ft_putstr(mr_ant.ant_name);
        ft_putchar('-');
        ft_putstr(mr_ant.room->str);
        ft_putchar(' ');
        mr_ant.room = mr_ant.room->next;
    }
}

void    ft_move_ants(t_string *route, t_data *c)
{
    t_colony *ant_farm;
    t_colony *tmp;

    ant_farm = ft_get_ants(c);
    tmp = ant_farm;
    while (tmp)
    {
        tmp->ant.room = route->next;
        ft_get_moving(tmp->ant);
        tmp = tmp->next;
        ft_putchar('\n');
    }
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

void    ft_assign_routs(t_colony *ants, t_string *da_wae)
{
    while (ants)
    {
        ants->ant.room = da_wae;
        ants = ants->next;
    }
}

t_colony		*ft_pop(t_colony **head)
{
	t_colony	*pop;

	pop = NULL;
	if (!*head)
		return (NULL);
	pop = *head;
	*head = (*head)->next;
	pop->next = NULL;
	return (pop);
}

void		ft_push_to(t_colony **dest, t_colony **src)
{
    t_colony *tmp;

    tmp = ft_pop(src);
    tmp->ant.room = tmp->ant.room->next;
	ft_trans_ant(dest, tmp);
}

void        ft_move_ants_in_maize(t_colony **ants)
{
    t_colony *tmp;

    tmp = *ants;
    while (tmp)
    {
        tmp->ant.room = tmp->ant.room->next;
        tmp = tmp->next;
    }
}

void        ft_display(t_colony *ants)
{
    t_colony *tmp;

    tmp = ants;
    while (tmp)
    {
        ft_putstr(tmp->ant.ant_name);
        ft_putchar('-');
        ft_putstr(tmp->ant.room->str);
        ft_putchar(' ');
        tmp = tmp->next;
    }
    ft_putchar('\n');
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
    ft_putendl("test");
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

int     ft_bouncer(t_colony *ft_move_ants_in_maize, char *room)
{
    t_colony *tmp;
    
    tmp = ft_move_ants_in_maize;
    while (tmp)
    {
        if (ft_strequ(tmp->ant.room->str, room))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int     main(void)
{
    char    *line;
    t_data  *c;
    t_node  *map;
    t_string *q;
    t_string *input;
    t_colony *ants_in_start;
    t_colony *ants_in_maize;


    c = ft_memalloc(sizeof(t_data));
    map = NULL;
    line = NULL;
    ants_in_maize = NULL;
    while (get_next_line(0, &line))
        ft_append_string(&input, line);
    ft_process_input(input, c);
    
    ft_node_str_free(&input);
    free(input);
    
    ft_creat_links(&map, c);
    ft_add_coordinates(&map, c->cells);
    ft_show_input(c, map);
    q = ft_astar(c, map);

    ants_in_start =  ft_get_ants(c);
    ft_assign_routs(ants_in_start, q);
    ft_push_to(&ants_in_maize, &ants_in_start);
    ft_display(ants_in_maize);
    while (ants_in_maize)
    {
        ft_move_ants_in_maize(&ants_in_maize);
        if (ft_bouncer(ants_in_maize, q->next->str))
        {
            if (ants_in_start)
                ft_push_to(&ants_in_maize, &ants_in_start);
        }
        ft_display(ants_in_maize);
        ft_remove_ants_at_end(&ants_in_maize, c);
    }



    free(c->start);
    free(c->end);
    ft_node_str_free(&c->tubs);
    ft_node_free2(&c->cells);
    free(c);
    ft_free_map(&map);
    ft_node_str_free(&q);
    return (1);
}