#include "../includes/lem-in.h"

int     main(void)
{
    char    *line;
    int     count;
    char    **tmp;
    t_data  *c;
    t_node  *map;
    int     i;
    t_string *q;

    c = ft_memalloc(sizeof(t_data));
    map = NULL;
    count = 0;
    i = 0;
    line = NULL;
    while (get_next_line(0, &line))
    {
        if (count == 0)
            c->nb_ants = ft_atoi(line);
        else if (ft_strequ(line, "##start"))
        {
            free(line);
            get_next_line(0, &line);
            tmp = ft_strsplit(line, ' ');
            c->start = ft_strdup(tmp[0]);
            i = 0;
            while (tmp[i])
            {
                free(tmp[i]);
                i++;
            }
            free(tmp);
            tmp = NULL;
        }
        else if (ft_strequ(line, "##end"))
        {
            free(line);
            get_next_line(0, &line);
            tmp = ft_strsplit(line, ' ');
            c->end = ft_strdup(tmp[0]);
            i = 0;
            while (tmp[i])
            {
                free(tmp[i]);
                i++;
            }
            free(tmp);
            tmp = NULL;
        }
        else if (ft_strchr(line, '-'))
        {
            do
            {
                if (ft_strchr(line, '-'))
                    ft_append_string(&c->tubs, ft_strdup(line));
                else
                    break ;
                free(line);
            } while (get_next_line(0, &line));
        }
        free(line);
        count++;
    }
    while (c->tubs)
    {
        tmp = ft_strsplit(c->tubs->str, '-');
        if (ft_search_node(map, tmp[0]))
        {
            ft_add_neigbour(&map, tmp[0], ft_strdup(tmp[1]));
            i = 0;
            while (tmp[i])
            {
                free(tmp[i]);
                i++;
            }
            free(tmp);
            tmp = NULL;
        }
        else
        {
            ft_append(&map, ft_strdup(tmp[0]));
            ft_add_neigbour(&map, tmp[0], ft_strdup(tmp[1]));
            i = 0;
            while (tmp[i])
            {
                free(tmp[i]);
                i++;
            }
            free(tmp);
            tmp = NULL;
        }
        c->tubs = c->tubs->next;
    }
    ft_show_input(c, map);
    q = ft_astar(c, map);
    while (q)
    {
        ft_putendl(q->str);
        q = q->next;
    }
    free(c);
    return (1);
}