/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:11:59 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/21 14:23:12 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <fcntl.h>

static int		valid_arg(char *arg)
{
	return (ft_strequ(arg, "sa") || ft_strequ(arg, "sb") ||
			ft_strequ(arg, "ss") || ft_strequ(arg, "ra") ||
			ft_strequ(arg, "rb") || ft_strequ(arg, "pa") ||
			ft_strequ(arg, "pb") || ft_strequ(arg, "rr") ||
			ft_strequ(arg, "rra") || ft_strequ(arg, "rrb")
			|| ft_strequ(arg, "rra"));
}

static int		getcmd(t_list *a, t_list *b)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) > 0 && valid_arg(line))
	{
		ft_update(&a, &b, line);
		free(line);
	}
	if (line && !valid_arg(line))
		ft_putendl("error");
	else
		ft_putendl(ft_isdone(&a, &b) ? "OK" : "KO");
	return (0);
}

int				main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;

	init_check(ac, av, &a, &b);
	getcmd(a, b);
	ft_lstfree(&a);
	ft_lstfree(&b);
	return (0);
}
