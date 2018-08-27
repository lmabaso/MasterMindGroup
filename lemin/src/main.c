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

void    ft_refine_links(t_node **map)
{
    t_node *tmp;
    t_string *tmp1;

    tmp = *map;
    while (tmp)
    {
        tmp1 = tmp->data.neighbours;
        while (tmp1)
        {
            ft_add_neigbour(map, tmp1->str, ft_strdup(tmp->data.room_num));
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
}

int     main(void)
{
    char    *line;
    t_data  *c;
    t_node  *map;
    t_string *q;
    t_string *input;

    c = ft_memalloc(sizeof(t_data));
    map = NULL;
    line = NULL;
    while (get_next_line(0, &line))
        ft_append_string(&input, line);
    ft_process_input(input, c);
    ft_creat_links(&map, c);
    ft_refine_links(&map);
    ft_add_coordinates(&map, c->cells);
    ft_show_input(c, map);
    q = ft_astar(c, map);
    // ft_putnbr(ft_lst_str_len(q));
    while (q)
    {
        ft_putendl(q->str);
        q = q->next;
    }
    free(c);
    while (1)
        ;
    return (1);
}