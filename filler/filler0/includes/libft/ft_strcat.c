/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:32:32 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 08:36:46 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t slen;

	slen = ft_strlen(s1) + ft_strlen(s2);
	s1 += ft_strlen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1 - slen);
}
