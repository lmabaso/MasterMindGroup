/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:23:42 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/21 14:29:08 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_issorted(t_list **head)
{
	t_list	*tmp;

	if (!*head || !(*head)->next)
		return (1);
	tmp = *head;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ft_isrsorted(t_list **head)
{
	t_list	*tmp;

	if (!*head || !(*head)->next)
		return (1);
	tmp = *head;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ft_isdone(t_list **a, t_list **b)
{
	return (ft_issorted(a) && b == NULL) ? 1 : 0;
}
