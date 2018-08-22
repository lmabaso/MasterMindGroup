/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:31:39 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/22 12:34:39 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_update(t_list **a, t_list **b, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		ft_swap(a);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		ft_swap(b);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		ft_push_to(a, b);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		ft_push_to(b, a);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ft_rotate_up(a);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		ft_rotate_up(b);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		ft_rotate_dwn(a);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		ft_rotate_dwn(b);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		ft_rotate_up_rr(a, b);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		ft_rotate_dwn_rr(a, b);
	if (ft_strncmp(cmd, "ok", 2) != 0)
		ft_putendl(cmd);
}
