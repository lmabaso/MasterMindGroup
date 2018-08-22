/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:15:41 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/22 13:17:40 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_b_rot(int len, int pos, char **rot)
{
	(pos > len / 2) ? ft_strcpy(*rot, "rrb") : ft_strcpy(*rot, "rb");
	return (((pos > len / 2) && (len > 2)) ? len - pos : pos);
}

int				ft_a_rot(int len, int pos, char **rot)
{
	(pos > len / 2) ? ft_strcpy(*rot, "rra") : ft_strcpy(*rot, "ra");
	return (((pos > len / 2) && (len > 2)) ? len - pos : pos);
}
