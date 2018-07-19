/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:29:07 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 08:39:09 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	if (!(ptr = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		*ptr++ = *s++;
		i++;
	}
	*ptr = '\0';
	return (ptr - i);
}
