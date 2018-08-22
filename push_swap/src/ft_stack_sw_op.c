/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sw_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:30:12 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/22 12:31:03 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list **head)
{
	int	*tmp;

	tmp = 0;
	if (*head && (*head)->next)
	{
		tmp = (*head)->content;
		(*head)->content = (*head)->next->content;
		(*head)->next->content = tmp;
	}
}

void	ft_swap_ss(t_list **head_a, t_list **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
}
