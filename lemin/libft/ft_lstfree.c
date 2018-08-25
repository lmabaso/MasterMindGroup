/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:04:28 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 11:04:42 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **head)
{
	t_list  *current;
    t_list  *next;

    current = *head;
    while (current != NULL)
    {
        next = current->next;
        free(current->content);
        free(current);
        current = next;
    }
    *head = NULL;
}
