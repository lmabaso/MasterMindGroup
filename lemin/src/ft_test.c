#include "../includes/lem-in.h"

void    ft_show_input(t_data *c, t_node *map)
{
    t_string *tmp;

    ft_putendl("++++++Data+++++++");
    ft_putnbr(c->nb_ants);
    ft_putchar('\n');
    ft_putstr("start: ");
    ft_putendl(c->start);
    ft_putstr("end: ");
    ft_putendl(c->end);
    ft_putendl("");
    while (map)
    {
        ft_putstr("Room: ");
        ft_putstr(map->data.room_num);
        ft_putstr("                 ");
        ft_putnbr(map->data.pos.x);
        ft_putstr(" ");
        ft_putnbr(map->data.pos.y);
        ft_putstr("\n");
        ft_putstr("Room links: ");
        tmp = map->data.neighbours;
        while (tmp)
        {
            ft_putstr(tmp->str);
            tmp =tmp->next;
            if (tmp)
                ft_putstr(" and ");
        }
        ft_putchar('\n');
        ft_putchar('\n');
        map = map->next;
    }
    ft_putendl("++++++End+++++++");
}