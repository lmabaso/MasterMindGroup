/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:26:57 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/22 13:27:59 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_place_in_b(t_list **b, int elem, char *rot)
{
	int			i;
	int			place;
	int			len;
	t_list		*tmp;

	i = 1;
	place = 0;
	tmp = *b;
	len = ft_lstlen(*b);
	while (i < len)
	{
		if (elem < ft_first(&tmp) && elem > ft_second(&tmp))
		{
			place = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (ft_b_rot(len, place, &rot));
}

int				ft_place_in_a(t_list **a, int elem, char *rot)
{
	int			i;
	int			place;
	int			len;
	t_list		*tmp;

	len = ft_lstlen(*a);
	i = 1;
	place = 0;
	tmp = *a;
	if (elem > ft_max(a) || elem < ft_min(a))
		place = ft_pos(a, ft_min(a));
	else
		while (i < len)
		{
			if (elem > ft_first(&tmp) && elem < ft_second(&tmp))
			{
				place = i;
				break ;
			}
			tmp = tmp->next;
			i++;
		}
	return (ft_a_rot(len, place, &rot));
}
