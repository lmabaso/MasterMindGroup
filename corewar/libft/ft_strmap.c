/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:20:49 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/29 12:35:51 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		len;

	if (!s || !(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	len = 0;
	while (*s)
	{
		tmp[len] = (*f)(*s++);
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
