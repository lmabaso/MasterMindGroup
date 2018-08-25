/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:27:32 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 09:29:32 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s || !(ptr = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start++];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
