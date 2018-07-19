/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:21:32 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 09:24:24 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	len;

	if (!s || !(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	len = 0;
	while (*s)
	{
		tmp[len] = (*f)(len, *s++);
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
