#include "../includes/lem-in.h"

void    ft_show_input(t_data *c, t_node *map)
{
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
        ft_putendl(map->data.room_num);
        ft_putstr("Room links: ");
        while (map->data.neighbours)
        {
            ft_putstr(map->data.neighbours->str);
            map->data.neighbours = map->data.neighbours->next;
            if (map->data.neighbours)
                ft_putstr(" and ");
        }
        ft_putchar('\n');
        ft_putchar('\n');
        map = map->next;
    }
    ft_putendl("++++++End+++++++");
}