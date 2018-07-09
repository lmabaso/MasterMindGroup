/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:11:11 by lmabaso           #+#    #+#             */
/*   Updated: 2017/08/25 13:25:22 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list      *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list  *sorting;

	if (lst)
	{
		sorting = f(lst);
		sorting->next = ft_lstmap(lst->next, f);
		return (sorting);
	}
	return (NULL);
}
